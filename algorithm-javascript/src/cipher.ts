export function findSignatureCounts(arr: number[]) {
  let t = arr.map((x) => [x, 0, false]);
  while (true) {
    const r = t.filter((tt) => !tt[2]);
    if (r.length === 0) break;
    r.forEach(([x, c], _i, t2) => {
      t[Number(x) - 1] = [x, Number(c) + 1, t2[Number(x) - 1][0] == x];
    });
  }
  return t.map((tt) => tt[1]);
}
