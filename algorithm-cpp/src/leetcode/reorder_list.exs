import ExUnit.Assertions

defmodule ReorderList do
  require Integer

  def solve(data) do
    traverse(data, data |> Enum.reverse())
    |> Stream.take(length(data))
    |> Enum.to_list()
  end

  def traverse([], rest) do
    rest
  end

  def traverse([head | rest], next) do
    Stream.concat([head], traverse(next, rest))
  end
end

assert ReorderList.solve([1, 2, 3, 4]) == [1, 4, 2, 3]
assert ReorderList.solve([1, 2, 3, 4, 5]) == [1, 5, 2, 4, 3]
