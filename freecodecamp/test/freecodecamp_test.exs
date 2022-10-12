defmodule FreecodecampTest do
  use ExUnit.Case
  doctest FreeCodeCamp

  test "greets the world" do
    assert FreeCodeCamp.hello() == :world
  end
end
