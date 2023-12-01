defmodule Algorithm.Freecodecamp.TabCanConstructTest do
  use ExUnit.Case
  alias Algorithm.FreeCodeCamp.TabCanConstruct, as: S

  test "solve" do
    assert [true] = S.solve("", ["a", "b"])
  end
end
