defmodule FreeCodeCamp.TreeCanSum do
  def solve(target, numbers, memo \\ %{})

  def solve(0, _numbers, memo) do
    {true, memo}
  end

  def solve(target, _numbers, memo) when target < 0 do
    {false, memo}
  end

  def solve(target, numbers, memo) do
    case Map.get(memo, target) do
      nil ->
        {results, memo} =
          numbers
          |> Enum.map(&(target - &1))
          |> Enum.map_reduce(memo, fn target, memo ->
            {result, memo} = solve(target, numbers, memo)
            {result, Map.put(memo, target, result)}
          end)

        {Enum.any?(results), memo}

      memoized ->
        {memoized, memo}
    end
  end
end
