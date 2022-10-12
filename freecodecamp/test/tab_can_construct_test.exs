defmodule Freecodecamp.TabCanConstructTest do
  use ExUnit.Case
  alias FreeCodeCamp.TabCanConstruct, as: S

  test "solve" do
    assert [true] == S.solve("", ["a", "b"])

    assert true == S.solve("abcdef", ["ab", "abc", "cd", "def", "abcd"])
  end
end
