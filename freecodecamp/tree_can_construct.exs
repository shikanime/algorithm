#!/usr/bin/env elixir

import ExUnit.Assertions

defmodule TreeCanConstruct do
  def solve(target, words, memo \\ %{})

  def solve("", _words, memo) do
    {true, memo}
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

    {Enum.any?(results), memo}
  end
end

assert({true, _} = TreeCanConstruct.solve("", ["a", "b"]))

assert(
  {false, _} =
    TreeCanConstruct.solve("abcdef", [
      "ab",
      "adc",
      "cd",
      "def",
      "abcd"
    ])
)

assert(
  {false, _} =
    TreeCanConstruct.solve("skateboard", [
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
  {false, _} =
    TreeCanConstruct.solve("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
      "e",
      "ee",
      "eee",
      "eeee",
      "eeeeee",
      "eeeeeee"
    ])
)
