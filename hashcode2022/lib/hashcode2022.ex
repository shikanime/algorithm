defmodule Hashcode2022 do
  def solve do
    {contributors, projects} =
      File.open!(
        "#{:code.priv_dir(:hashcode2022)}/a_an_example.in.txt",
        &Hashcode2022.IO.read(&1)
      )

    estimations =
      for project <- projects do
        contributors
        |> Enum.filter(&Hashcode2022.eligible?(project, &1))
        |> Enum.sort_by(&Hashcode2022.compatiblity(project, &1))
        |> Enum.flat_map_reduce(project, &Hashcode2022.assign(&2, &1))
      end

    tasks = Enum.filter(estimations, &(length(elem(&1, 0)) > 0))

    File.touch!("#{:code.priv_dir(:hashcode2022)}/a_an_example.out.txt")

    File.open!(
      "#{:code.priv_dir(:hashcode2022)}/a_an_example.out.txt",
      [:write],
      &Hashcode2022.IO.write(&1, tasks)
    )
  end

  def eligible?(project, contributor) do
    Enum.any?(contributor.skills, &has_skill?(project, &1))
  end

  defp has_skill?(project, {name, skill}) do
    if requirement = Keyword.get(project.requirements, name) do
      skill >= requirement
    else
      false
    end
  end

  def compatiblity(project, contributor) do
    contributor.skills
    |> Enum.map(fn {name, skill} ->
      if requirement = Keyword.get(project.requirements, name) do
        skill - requirement
      else
        0
      end
    end)
    |> Enum.sum()
  end

  def assign(project, contributor) do
    requirements = Map.get(project, :requirements)

    {assignments, requirements} =
      Enum.map_reduce(contributor.skills, requirements, fn {name, skill}, requirements ->
        case Keyword.get(requirements, name) do
          nil ->
            {{:rejected, contributor}, requirements}

          requirement when requirement >= 0 ->
            {{:assigned, contributor}, Keyword.put(requirements, name, skill - requirement)}
        end
      end)

    assignments =
      assignments
      |> Enum.filter(fn {status, _assignment} -> status == :assigned end)
      |> Enum.map(fn {_status, assignment} -> assignment end)

    {assignments, Map.put(project, :requirements, requirements)}
  end
end

defmodule Hashcode2022.IO do
  defp read_line(device) do
    device
    |> IO.read(:line)
    |> String.trim()
    |> String.split(" ")
    |> List.to_tuple()
  end

  defp read_contributor(device) do
    {name, skills} = read_score(device)

    skills =
      0..(skills - 1)
      |> Enum.map(fn _ -> read_score(device) end)
      |> Keyword.new()

    %{
      name: name,
      skills: skills
    }
  end

  defp read_project_header(device) do
    {name, budget, reward, soft_deadline, requirements} = read_line(device)

    {
      name,
      String.to_integer(budget),
      String.to_integer(reward),
      String.to_integer(soft_deadline),
      String.to_integer(requirements)
    }
  end

  defp read_score(device) do
    {name, requirement} = read_line(device)
    {String.to_atom(name), String.to_integer(requirement)}
  end

  defp read_project(device) do
    {name, budget, reward, soft_deadline, requirements} = read_project_header(device)

    requirements =
      0..(requirements - 1)
      |> Enum.map(fn _ -> read_score(device) end)
      |> Keyword.new()

    %{
      name: name,
      budget: budget,
      reward: reward,
      soft_deadline: soft_deadline,
      requirements: requirements
    }
  end

  defp read_header(device) do
    {contributors, projects} = read_line(device)
    {String.to_integer(contributors), String.to_integer(projects)}
  end

  def read(device) do
    {contributors, projects} = read_header(device)

    contributors =
      for _ <- 0..(contributors - 1) do
        read_contributor(device)
      end

    projects =
      for _ <- 0..(projects - 1) do
        read_project(device)
      end

    {contributors, projects}
  end

  def write(device, tasks) do
    IO.write(device, format_report(tasks))
  end

  def format_report(tasks) do
    header = [length(tasks) |> to_string()]

    body =
      Enum.flat_map(tasks, fn {contributors, project} ->
        [
          project.name,
          contributors
          |> Enum.map(&Atom.to_string(&1.name))
          |> Enum.intersperse(" ")
        ]
      end)

    Enum.intersperse(header ++ body, "\n")
  end
end
