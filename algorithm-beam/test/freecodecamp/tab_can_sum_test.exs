defmodule Algorithm.Freecodecamp.TabCanSumTest do
  use ExUnit.Case
  alias Algorithm.FreeCodeCamp.TabCanSum, as: S

  test "solve" do
    assert [
             true,
             false,
             false,
             true,
             true,
             true,
             true,
             true
           ] = S.solve(7, [5, 3, 4])
  end
end
