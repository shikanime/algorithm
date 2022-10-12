defmodule Algorithm.FreeCodeCamp.TreeCountConstructTest do
  use ExUnit.Case
  alias Algorithm.FreeCodeCamp.TreeCountConstruct, as: S

  test "solve" do
    assert {1, _} = S.solve("", ["a", "b"])

    assert {1, _} =
             S.solve("abcdef", [
               "ab",
               "abc",
               "cd",
               "def",
               "abcd"
             ])

    assert {0, _} =
             S.solve("skateboard", [
               "bo",
               "rd",
               "ate",
               "t",
               "ska",
               "sk",
               "boar"
             ])

    assert {0, _} =
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

    assert {2, _} =
             S.solve("purple", [
               "purp",
               "p",
               "ur",
               "le",
               "purpl"
             ])
  end
end
