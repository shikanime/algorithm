defmodule FreeCodeCamp.TabFib do
  def solve(n) do
    [0, 1 | List.duplicate(0, n - 1)]
    |> do_solve()
    |> List.last()
  end

  defp do_solve([head, a]) do
    [head, head + a]
  end

  defp do_solve([head, a, b | tail]) do
    [head | do_solve([head + a, head + b | tail])]
  end
end
