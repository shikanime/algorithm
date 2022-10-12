defmodule Algorithm.Freecodecamp.TreeHowSumTest do
  use ExUnit.Case
  alias Algorithm.FreeCodeCamp.TreeHowSum, as: S

  test "solve" do
    assert {[], _} = S.solve(0, [2, 3])
    assert {[2, 2, 3], _} = S.solve(7, [2, 3])
    assert {[3, 4], _} = S.solve(7, [5, 3, 4, 7])
    assert {:error, _} = S.solve(7, [2, 4])
    assert {[2, 2, 2, 2], _} = S.solve(8, [2, 3, 5])
    assert {:error, _} = S.solve(300, [7, 14])
  end
end
