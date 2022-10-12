defmodule FreeCodeCamp.TabCanSum do
  def solve(target, numbers) when is_number(target) do
    solve([true | List.duplicate(false, target)], numbers)
  end

  def solve([], _numbers) do
    []
  end

  def solve([true | tail], numbers) do
    [
      true
      | solve(
          tail
          |> Enum.with_index(1)
          |> Enum.map(&toggle(&1, numbers)),
          numbers
        )
    ]
  end

  def solve([false | tail], numbers) do
    [false | solve(tail, numbers)]
  end

  defp toggle({true, _idx}, _numbers), do: true
  defp toggle({false, idx}, numbers), do: idx in numbers
end
