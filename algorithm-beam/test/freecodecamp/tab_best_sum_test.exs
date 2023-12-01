defmodule Algorithm.Freecodecamp.TabBestSumTest do
  use ExUnit.Case
  alias Algorithm.FreeCodeCamp.TabBestSum, as: S

  test "solve" do
    assert [7] = S.solve(7, [5, 3, 4, 7]) |> List.last()
    assert [3, 5] = S.solve(8, [2, 3, 5]) |> List.last()
    assert [4, 4] = S.solve(8, [1, 4, 5]) |> List.last()
    assert [25, 25, 25, 25] = S.solve(100, [1, 2, 5, 25]) |> List.last()
  end
end
