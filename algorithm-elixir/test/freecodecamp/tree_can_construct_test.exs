defmodule Algorithm.FreeCodeCamp.TreeCanConstructTest do
  use ExUnit.Case
  alias Algorithm.FreeCodeCamp.TreeCanConstruct, as: S

  test "solve" do
    assert {true, _} = S.solve("", ["a", "b"])

    assert {false, _} =
             S.solve("abcdef", [
               "ab",
               "adc",
               "cd",
               "def",
               "abcd"
             ])

    assert {false, _} =
             S.solve("skateboard", [
               "bo",
               "rd",
               "ate",
               "t",
               "ska",
               "sk",
               "boar"
             ])

    assert {false, _} =
             S.solve(
               "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
               [
                 "e",
                 "ee",
                 "eee",
                 "eeee",
                 "eeeeee",
                 "eeeeeee"
               ]
             )
  end
end
