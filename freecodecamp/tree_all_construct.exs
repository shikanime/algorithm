#!/usr/bin/env elixir

import ExUnit.Assertions

defmodule TreeAllConstruct do
  def solve(target, words, memo \\ %{})

  def solve("", _words, memo) do
    {[[]], memo}
  end

  def solve(target, words, memo) do
    case Map.get(memo, target) do
      nil -> do_solve(target, words, memo)
      memoized -> {memoized, memo}
    end
  end

  def do_solve(target, words, memo) do
    {results, memo} =
      words
      |> Enum.filter(&String.starts_with?(target, &1))
      |> Enum.map(&{&1, String.slice(target, String.length(&1)..-1)})
      |> Enum.flat_map_reduce(memo, fn {word, target}, memo ->
        {combinaisons, memo} = solve(target, words, memo)

        {
          Enum.map(combinaisons, &[word | &1]),
          Map.put(memo, target, combinaisons)
        }
      end)

    {Enum.filter(results, &(length(&1) >= 1)), memo}
  end
end

assert({[[]], _} = TreeAllConstruct.solve("", ["a", "b"]))

assert(
  {
    [
      ["ab", "c", "def"],
      ["ab", "cd", "ef"],
      ["abc", "def"],
      ["abcd", "ef"]
    ],
    _
  } =
    TreeAllConstruct.solve("abcdef", [
      "ab",
      "abc",
      "c",
      "cd",
      "def",
      "abcd",
      "ef"
    ])
)

assert(
  {[], _} =
    TreeAllConstruct.solve("skateboard", [
      "bo",
      "rd",
      "ate",
      "t",
      "ska",
      "sk",
      "boar"
    ])
)

assert(
  {[], _} =
    TreeAllConstruct.solve("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
      "e",
      "ee",
      "eee",
      "eeee",
      "eeeeee",
      "eeeeeee"
    ])
)

assert(
  {[["purp", "le"], ["p", "ur", "p", "le"]], _} =
    TreeAllConstruct.solve("purple", [
      "purp",
      "p",
      "ur",
      "le",
      "purpl"
    ])
)
