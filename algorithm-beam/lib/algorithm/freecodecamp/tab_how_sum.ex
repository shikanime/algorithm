defmodule Algorithm.FreeCodeCamp.TabHowSum do
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

  defp toggle({nil, idx}, numbers, combinaisons) do
    if number = Enum.find(numbers, &(&1 == idx)) do
      [number | combinaisons]
    end
  end

  defp toggle({combinaison, _idx}, _numbers, _combinaisons) do
    combinaison
  end
end
