defmodule Freecodecamp.TabFibTest do
  use ExUnit.Case
  alias FreeCodeCamp.TabFib, as: S

  test "solve" do
    assert 8 == S.solve(6)
    assert 13 == S.solve(7)
    assert 21 == S.solve(8)
    assert 12_586_269_025 == S.solve(50)
  end
end
