defmodule HashCode2022 do
  def run do
    {contributors, projects} = HashCode2022.IO.read(:stdio)
    tasks = HashCode2022.Solver.solve(contributors, projects)
    HashCode2022.IO.write(:stdio, tasks)
  end
end
