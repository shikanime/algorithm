defmodule Algorithm.HashCode2022 do
  def run do
    {contributors, projects} = Algorithm.HashCode2022.IO.read(:stdio)
    tasks = Algorithm.HashCode2022.Solver.solve(contributors, projects)
    Algorithm.HashCode2022.IO.write(:stdio, tasks)
  end
end
