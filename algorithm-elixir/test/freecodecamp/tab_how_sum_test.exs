defmodule Algorithm.Freecodecamp.TabHowSumTest do
  use ExUnit.Case
  alias Algorithm.FreeCodeCamp.TabHowSum, as: S

  test "solve" do
    assert [
             [],
             nil,
             nil,
             [3],
             [4],
             [5],
             [3, 3],
             [4, 3]
           ] = S.solve(7, [5, 3, 4])
  end
end
