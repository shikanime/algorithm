defmodule FreeCodeCamp.TreeAllConstruct do
  def solve(target, words, memo \\ %{})

  def solve("", _words, memo) do
    {[[]], memo}
  end

  def solve(target, words, memo) do
    case Map.get(memo, target) do
      nil -> do_solve(target, words, memo)
      memoized -> {memoized, memo}
    end
  end

  def do_solve(target, words, memo) do
    {results, memo} =
      words
      |> Enum.filter(&String.starts_with?(target, &1))
      |> Enum.map(&{&1, String.slice(target, String.length(&1)..-1)})
      |> Enum.flat_map_reduce(memo, fn {word, target}, memo ->
        {combinaisons, memo} = solve(target, words, memo)

        {
          Enum.map(combinaisons, &[word | &1]),
          Map.put(memo, target, combinaisons)
        }
      end)

    {Enum.filter(results, &(length(&1) >= 1)), memo}
  end
end
