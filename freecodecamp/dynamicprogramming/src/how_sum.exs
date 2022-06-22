#!/usr/bin/env elixir

defmodule HowSum do
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

  def do_solve(target, numbers, memo) do
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
      |> List.first(:error),
      memo
    }
  end
end

for {target, numbers} <- [
      {0, [2, 3]},
      {7, [2, 3]},
      {7, [5, 3, 4, 7]},
      {7, [2, 4]},
      {8, [2, 3, 5]},
      {300, [7, 14]}
    ] do
  {path, _memo} = HowSum.solve(target, numbers)
  IO.inspect(%{target: target, numbers: numbers, path: path})
end
