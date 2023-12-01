defmodule Algorithm.Freecodecamp.TreeBestSumTest do
  use ExUnit.Case
  alias Algorithm.FreeCodeCamp.TreeBestSum, as: S

  test "solve" do
    assert {[3, 4], _} = S.solve(7, [5, 3, 4, 7])
    assert {[2, 2, 2, 2], _} = S.solve(8, [2, 3, 5])
    assert {[1, 1, 1, 1, 1, 1, 1, 1], _} = S.solve(8, [1, 4, 5])
    path = List.duplicate(1, 100)
    assert {^path, _} = S.solve(100, [1, 2, 5, 25])
  end
end
