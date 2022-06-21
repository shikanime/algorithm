type Memo = { [key: number]: boolean };

const canSum = (
  target: number,
  numbers: number[],
  memo: Memo = { [0]: true }
): boolean => {
  if (target < 0) return false;
  if (target in memo) return memo[target];
  return (memo[target] = doCanSum(numbers, target, memo));
};

const doCanSum = (numbers: number[], target: number, memo: Memo): boolean =>
  numbers.some((num) => canSum(target - num, numbers, memo));

console.log(canSum(7, [2, 3]));
console.log(canSum(7, [5, 3, 4, 7]));
console.log(canSum(7, [2, 4]));
console.log(canSum(8, [2, 3, 5]));
console.log(canSum(300, [7, 14]));
