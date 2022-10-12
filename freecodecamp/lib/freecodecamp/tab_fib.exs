import ExUnit.Assertions

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

assert(8 == FreeCodeCamp.TabFib.solve(6))
assert(13 == FreeCodeCamp.TabFib.solve(7))
assert(21 == FreeCodeCamp.TabFib.solve(8))
assert(12_586_269_025 == FreeCodeCamp.TabFib.solve(50))
