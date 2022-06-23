#!/usr/bin/env elixir

import ExUnit.Assertions

defmodule CanConstruct do
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

assert({true, _} = CanConstruct.solve("", ["a", "b"]))

assert(
  {false, _} =
    CanConstruct.solve("abcdef", [
      "ab",
      "adc",
      "cd",
      "def",
      "abcd"
    ])
)

assert(
  {false, _} =
    CanConstruct.solve("skateboard", [
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
    CanConstruct.solve("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
      "e",
      "ee",
      "eee",
      "eeee",
      "eeeeee",
      "eeeeeee"
    ])
)
