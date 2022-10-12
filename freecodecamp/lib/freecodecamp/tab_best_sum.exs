import ExUnit.Assertions

defmodule FreeCodeCamp.TabBestSum do
  def solve(target, numbers) when is_number(target) do
    solve([[] | List.duplicate(nil, target)], numbers)
  end

  def solve([], _numbers) do
    []
  end

  def solve([nil | tail], numbers) do
    [nil | solve(tail, numbers)]
  end

  def solve([combinaisons | tail], numbers) do
    result =
      tail
      |> Enum.with_index(1)
      |> Enum.map(&toggle(&1, numbers, combinaisons))

    [combinaisons | solve(result, numbers)]
  end

  defp toggle({combinaison, idx}, numbers, combinaisons) do
    numbers
    |> Enum.filter(&(&1 == idx))
    |> Enum.map(&[&1 | combinaisons])
    |> Enum.concat([combinaison])
    |> Enum.reject(&is_nil/1)
    |> Enum.min_by(&length/1, fn -> nil end)
  end
end

assert([7] == List.last(FreeCodeCamp.TabBestSum.solve(7, [5, 3, 4, 7])))

assert([3, 5] == List.last(FreeCodeCamp.TabBestSum.solve(8, [2, 3, 5])))

assert([4, 4] == List.last(FreeCodeCamp.TabBestSum.solve(8, [1, 4, 5])))

assert([25, 25, 25, 25] == List.last(FreeCodeCamp.TabBestSum.solve(100, [1, 2, 5, 25])))
