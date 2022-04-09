# 2    # There are two graphs (or queries as the problem describes)
# 4 2  # 4 nodes and 2 edges for 1st graph
# 1 2  # An edge from node 1 to node 2
# 1 3  # An edge from node 1 to node 3
# 1    # Starting from node 1
# 3 1  # 3 nodes and 1 edge for 2nd graph
# 2 3  # An edge from node 2 to node 3
# 2    # Starting from node 2

defmodule CrackTheCodeInterview.BFS do
  def bfs(graph, entrypoint) do
    bfs(graph, %{}, entrypoint)
  end

  defp bfs(graph, state, _entrypoint) when map_size(graph) == 0 do
    state
  end

  defp bfs(graph, state, entrypoint) do
    {node, rest} = Map.pop(graph, entrypoint, MapSet.new())
    IO.inspect([entrypoint, graph, rest, node])

    node
    |> MapSet.to_list()
    |> Enum.reduce(Map.put(state, entrypoint, node), fn n, state ->
      bfs(rest, state, n)
    end)
  end
end

defmodule CrackTheCodeInterview.BFS.Data do
  def read do
    nodes = Map.new(Range.new(0, 3), &{&1, MapSet.new()})
    edges = [{1, 2}, {1, 3}]

    Enum.reduce(edges, nodes, fn {a, b}, acc ->
      Map.update!(acc, a, &MapSet.put(&1, b))
    end)
  end
end

defmodule CrackTheCodeInterview.BFS.Solver do
  def solve do
    CrackTheCodeInterview.BFS.Data.read() |> CrackTheCodeInterview.BFS.bfs(1)
  end
end
