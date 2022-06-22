#!/usr/bin/env elixir

import ExUnit.Assertions

defmodule CanConstruct do
  def solve(target, words)

  def solve("", _words) do
    true
  end

  def solve(target, words) do
    words
    |> Enum.filter(&String.starts_with?(target, &1))
    |> Enum.map(fn word ->
      solve(String.slice(target, String.length(word)..-1), words)
    end)
    |> Enum.any?()
  end
end

assert(CanConstruct.solve("", ["a", "b"]))
refute(CanConstruct.solve("abcdef", ["ab", "adc", "cd", "def", "abcd"]))
refute(CanConstruct.solve("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]))

# refute(
#   CanConstruct.solve("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
#     "e",
#     "ee",
#     "eee",
#     "eeee",
#     "eeeeee",
#     "eeeeeee"
#   ])
# )
