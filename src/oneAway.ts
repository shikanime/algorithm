function scoreOneAway(a: string, b: string, scores: number[]): number {
  if (a.length === 0) {
    return scores.reduce((a, b) => a + b);
  }
  return scoreOneAwayCompare(a, b, scores);
}

function scoreOneAwayCompare(a: string, b: string, scores: number[]): number {
  if (a[0] === b[0]) {
    return scoreOneAway(a.slice(1), b.slice(1), [1, ...scores]);
  }
  return scoreOneAwayEdition(a, b, scores);
}

function scoreOneAwayEdition(a: string, b: string, scores: number[]): number {
  const next = b.indexOf(a[0]);
  if (next !== -1) {
    return scoreOneAway(
      a,
      b.slice(next),
      scores
        .slice(0, next)
        .filter((x) => x !== -1)
        .concat(scores.slice(next))
    );
  }
  return scoreOneAwayDeletion(a, b, scores);
}

function scoreOneAwayDeletion(a: string, b: string, scores: number[]): number {
  return scoreOneAway(a.slice(1), b, [-1, ...scores]);
}

function oneAway(a: string, b: string): boolean {
  return scoreOneAway(a, b, []) >= b.length - 1;
}

console.log(oneAway("pale", "pppple"));
