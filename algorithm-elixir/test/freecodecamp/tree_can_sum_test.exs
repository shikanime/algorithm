defmodule Algorithm.FreeCodeCamp.TreeCanSumTest do
  use ExUnit.Case
  alias Algorithm.FreeCodeCamp.TreeCanSum, as: S

  test "solve" do
    assert {true, _} = S.solve(7, [2, 3])
    assert {true, _} = S.solve(7, [5, 3, 4, 7])
    assert {false, _} = S.solve(7, [2, 4])
    assert {true, _} = S.solve(8, [2, 3, 5])
    assert {false, _} = S.solve(300, [7, 14])
  end
end
