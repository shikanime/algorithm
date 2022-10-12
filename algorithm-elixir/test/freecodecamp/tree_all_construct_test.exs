defmodule Algorithm.Freecodecamp.TreeAllConstructTest do
  use ExUnit.Case
  alias Algorithm.FreeCodeCamp.TreeAllConstruct, as: S

  test "solve" do
    assert {[[]], _} = S.solve("", ["a", "b"])

    assert {
             [
               ["ab", "c", "def"],
               ["ab", "cd", "ef"],
               ["abc", "def"],
               ["abcd", "ef"]
             ],
             _
           } =
             S.solve("abcdef", [
               "ab",
               "abc",
               "c",
               "cd",
               "def",
               "abcd",
               "ef"
             ])

    assert {[], _} =
             S.solve("skateboard", [
               "bo",
               "rd",
               "ate",
               "t",
               "ska",
               "sk",
               "boar"
             ])

    assert {[], _} =
             S.solve("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
               "e",
               "ee",
               "eee",
               "eeee",
               "eeeeee",
               "eeeeeee"
             ])

    assert {[["purp", "le"], ["p", "ur", "p", "le"]], _} =
             S.solve("purple", [
               "purp",
               "p",
               "ur",
               "le",
               "purpl"
             ])
  end
end
