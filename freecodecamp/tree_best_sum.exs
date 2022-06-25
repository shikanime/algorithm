#!/usr/bin/env elixir

defmodule TreeHowSum do
  def solve(target, numbers, memo \\ %{})

  def solve(0, _numbers, memo) do
    {[], memo}
  end

  def solve(target, _numbers, memo) when target < 0 do
    {:error, memo}
  end

  def solve(target, numbers, memo) do
    if memoized = Map.get(memo, target) do
      {memoized, memo}
    else
      do_solve(target, numbers, memo)
    end
  end

  defp do_solve(target, numbers, memo) do
    {paths, memo} =
      numbers
      |> Enum.map(&{&1, target - &1})
      |> Enum.map_reduce(memo, fn {number, target}, memo ->
        case solve(target, numbers, memo) do
          {:error, memo} ->
            {:error, Map.put(memo, target, :error)}

          {path, memo} ->
            {[number | path], Map.put(memo, target, path)}
        end
      end)

    {
      paths
      |> Enum.reject(&(&1 == :error))
      |> Enum.max_by(&length/1, fn -> :error end),
      memo
    }
  end
end

for {target, numbers} <- [
      {7, [5, 3, 4, 7]},
      {8, [2, 3, 5]},
      {8, [1, 4, 5]},
      {100, [1, 2, 5, 25]}
    ] do
  {path, _memo} = TreeHowSum.solve(target, numbers)
  IO.inspect(%{target: target, numbers: numbers, path: path})
end
