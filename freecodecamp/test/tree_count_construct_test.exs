defmodule FreeCodeCamp.TreeCountConstructTest do
  use ExUnit.Case
  alias FreeCodeCamp.TreeCountConstruct, as: S

  test "solve" do
    assert {1, _} = FreeCodeCamp.TreeCountConstruct.solve("", ["a", "b"])

    assert {1, _} =
             FreeCodeCamp.TreeCountConstruct.solve("abcdef", [
               "ab",
               "abc",
               "cd",
               "def",
               "abcd"
             ])

    assert {0, _} =
             FreeCodeCamp.TreeCountConstruct.solve("skateboard", [
               "bo",
               "rd",
               "ate",
               "t",
               "ska",
               "sk",
               "boar"
             ])

    assert {0, _} =
             FreeCodeCamp.TreeCountConstruct.solve(
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
             FreeCodeCamp.TreeCountConstruct.solve("purple", [
               "purp",
               "p",
               "ur",
               "le",
               "purpl"
             ])
  end
end
