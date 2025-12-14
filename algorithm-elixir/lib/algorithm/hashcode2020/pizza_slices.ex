defmodule Algorithm.HashCode2020.PizzaSlices.Solver do
  def solve(pizzas, n) do
    pizzas
    |> Enum.with_index()
    |> Enum.sort()
    |> Enum.reverse()
    |> do_solve(n)
  end

  defp do_solve(pizzas, n, m \\ 0, acc \\ [])

  defp do_solve([{pizza, idx} | rest], n, m, acc) when n >= m + pizza do
    do_solve(rest, n, pizza + m, [idx | acc])
  end

  defp do_solve([_ | rest], n, m, acc) do
    do_solve(rest, n, m, acc)
  end

  defp do_solve([], _, _, acc) do
    acc
  end
end

defmodule Algorithm.HashCode2020.PizzaSlices.IO do
  def read_header(device) do
    IO.read(device, :line)
    |> String.split()
    |> List.first()
    |> String.to_integer()
  end

  def read_pizzas(device) do
    IO.read(device, :line)
    |> String.split()
    |> Enum.map(&String.to_integer/1)
  end

  def put_types(device, orders) do
    orders
    |> length()
    |> IO.puts(device)
  end

  def put_orders(device, orders) do
    orders
    |> Enum.intersperse(" ")
    |> Enum.map(&to_string/1)
    |> IO.puts(device)
  end
end

defmodule Algorithm.HashCode2020.PizzaSlices do
  alias Algorithm.HashCode2020.PizzaSlices, as: PS

  def run do
    n = PS.IO.read_header(:stdio)
    pizzas = PS.IO.read_pizzas(:stdio)
    orders = PS.Solver.solve(pizzas, n)
    PS.IO.put_types(:stdio, orders)
    PS.IO.put_orders(:stdio, orders)
  end
end
