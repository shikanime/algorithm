import ExUnit.Assertions
require IEx

defmodule FreeCodeCamp.TabCanSum do
  def solve("", words) do
    [true]
  end

  def solve(target, words) do
    solve(
      [true | List.duplicate(false, String.length(target) + 1)],
      target,
      words
    )
  end

  def solve([], _target, _words) do
    []
  end

  def solve([false | rest], target, words) do
    [false | solve(rest, String.slice(target, 1..-1), words)]
  end

  def solve([true | rest], target, words) do
    [
      true
      | solve(
          rest
          |> Enum.with_index(1)
          |> Enum.map(fn
            {false, idx} ->
              Enum.any?(words, fn word ->
                target
                |> String.slice(idx..-1)
                |> String.starts_with?(word)
              end)

            {true, _idx} ->
              true
          end)
          |> IO.inspect(label: "#{target}"),
          String.slice(target, 1..-1),
          words
        )
    ]
  end
end

assert([true] == FreeCodeCamp.TabCanSum.solve("", ["a", "b"]))
assert(true == FreeCodeCamp.TabCanSum.solve("abcdef", ["ab", "abc", "cd", "def", "abcd"]))
