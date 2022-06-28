defmodule GoogleBooks do
  require Logger

  def solve(budget, libraries) do
    libraries = rank_libraries(libraries, budget)
    {signup_days, libraries} = select_libraries(libraries, budget)
    invest_libraries(libraries, budget - signup_days)
  end

  defp rank_libraries(libraries, budget) do
    Enum.sort_by(libraries, &score_library(&1, budget))
  end

  defp score_library({_, _, n_books, signup_days, n_concurent_book}, budget) do
    budget - n_books / n_concurent_book + signup_days
  end

  defp select_libraries(libraries, budget, offset \\ 0, res \\ [])

  defp select_libraries([library | rest], budget, offset, res) do
    {_, _, _, signup_days, _} = library

    case offset + signup_days do
      next when next <= budget ->
        select_libraries(rest, budget, next, [library | res])

      _ ->
        {offset, res}
    end
  end

  defp select_libraries([], _, offset, res) do
    {offset, res}
  end

  defp invest_libraries(libraries, days) do
    Enum.map(libraries, fn {n, books, n_books, _, n_concurent_book} ->
      process_books = floor((n_books - days) * n_concurent_book)
      {n, Enum.take(books, process_books)}
    end)
  end

  defp score_book(libraries, order) do
    Enum.sort_by(
      libraries,
      fn library ->
        {score, _} =
          order
          |> Enum.with_index()
          |> Enum.find(fn {_, index} -> library == index end)

        score
      end,
      :desc
    )
  end
end

defmodule GoogleBooks.IO do
  def read_header(device) do
    [n_books, n_libraries, n_days] = read_input(device) |> Enum.take(3)
    {n_books, n_libraries, n_days}
  end

  def read_books(device, n) do
    read_input(device) |> Enum.take(n)
  end

  def read_libraries(device, n) do
    Enum.map(0..(n - 1), fn n ->
      [n_books, signup_days, n_concurent_book] = read_input(device)
      books = read_input(device) |> Enum.take(n_books)
      {n, books, n_books, signup_days, n_concurent_book}
    end)
  end

  defp read_input(device) do
    read_list(device) |> Enum.map(&String.to_integer/1)
  end

  defp read_list(device) do
    IO.read(device, :line) |> String.trim() |> String.split(" ")
  end

  def format_libraries(libraries) do
    libraries
    |> Enum.map(fn {n, books} ->
      [
        [n |> to_string(), length(books) |> to_string()] |> Enum.intersperse(" "),
        books |> Enum.map(&to_string/1) |> Enum.intersperse(" ")
      ]
      |> Enum.intersperse("\n")
    end)
    |> Enum.reverse()
    |> Enum.intersperse("\n")
  end

  def put_libraries(device, libraries) do
    IO.puts(device, libraries |> length() |> to_string())
    IO.puts(device, libraries |> format_libraries())
  end
end

{n_books, n_libraries, budget} = GoogleBooks.IO.read_header(:stdio)
_order = GoogleBooks.IO.read_books(:stdio, n_books)
libraries = GoogleBooks.IO.read_libraries(:stdio, n_libraries)
libraries = GoogleBooks.solve(budget, libraries)
GoogleBooks.IO.put_libraries(:stdio, libraries)
