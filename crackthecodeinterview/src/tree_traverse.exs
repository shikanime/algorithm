defmodule Tree do
  defmodule Node do
    defstruct left: nil,
              right: nil,
              value: nil
  end

  def traverse(_mode, nil) do
    []
  end

  def traverse(:in, %Tree.Node{} = node) do
    traverse(:in, node.left)
    |> IO.inspect()
    |> Stream.concat([node.value])
    |> Stream.concat(traverse(:in, node.right))
  end

  def traverse(:pre, %Tree.Node{} = node) do
    [node.value]
    |> Stream.concat(traverse(:pre, node.left))
    |> Stream.concat(traverse(:pre, node.right))
  end

  def traverse(:post, %Tree.Node{} = node) do
    traverse(:post, node.left)
    |> Stream.concat(traverse(:post, node.right))
    |> Stream.concat([node.value])
  end
end
