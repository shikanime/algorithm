#!/usr/bin/env elixir

import ExUnit.Assertions

defmodule CountConstruct do
  def solve(target, words, memo \\ %{})

  def solve("", _words, memo) do
    {1, memo}
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
      |> Enum.map(&String.slice(target, String.length(&1)..-1))
      |> Enum.map_reduce(memo, fn target, memo ->
        {result, memo} = solve(target, words, memo)
        {result, Map.put(memo, target, result)}
      end)

    {Enum.count(results, &(&1 >= 1)), memo}
  end
end

assert({1, _} = CountConstruct.solve("", ["a", "b"]))

assert(
  {1, _} =
    CountConstruct.solve("abcdef", [
      "ab",
      "abc",
      "cd",
      "def",
      "abcd"
    ])
)

assert(
  {0, _} =
    CountConstruct.solve("skateboard", [
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
  {0, _} =
    CountConstruct.solve("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
      "e",
      "ee",
      "eee",
      "eeee",
      "eeeeee",
      "eeeeeee"
    ])
)

assert(
  {2, _} =
    CountConstruct.solve("purple", [
      "purp",
      "p",
      "ur",
      "le",
      "purpl"
    ])
)
