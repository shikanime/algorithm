defmodule Algorithm.CrackTheCodeInterview.TreeTraverse do
  defstruct left: nil,
            right: nil,
            value: nil

  def traverse(_mode, nil) do
    []
  end

  def traverse(:in, %__MODULE__{} = node) do
    traverse(:in, node.left)
    |> IO.inspect()
    |> Stream.concat([node.value])
    |> Stream.concat(traverse(:in, node.right))
  end

  def traverse(:pre, %__MODULE__{} = node) do
    [node.value]
    |> Stream.concat(traverse(:pre, node.left))
    |> Stream.concat(traverse(:pre, node.right))
  end

  def traverse(:post, %__MODULE__{} = node) do
    traverse(:post, node.left)
    |> Stream.concat(traverse(:post, node.right))
    |> Stream.concat([node.value])
  end
end
