// Add any extra import statements you may need here

// Add any helper functions you may need here

function findSignatureCounts(arr) {
  let t = arr.map((x) => [x, 0, false]);
  while (true) {
    const r = t.filter((tt) => !tt[2]);
    if (r.length === 0) break;
    r.forEach(([x, c, d], _i, t2) => {
      t[x - 1] = [x, c + 1, t2[x - 1][0] == x];
    });
  }
  return t.map((tt) => tt[1]);
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
function printintegerArray(array) {
  var size = array.length;
  var res = "";
  res += "[";
  var i = 0;
  for (i = 0; i < size; i++) {
    if (i !== 0) {
      res += ", ";
    }
    res += array[i];
  }
  res += "]";
  return res;
}

var test_case_number = 1;

function check(expected, output) {
  var expected_size = expected.length;
  var output_size = output.length;
  var result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (var i = 0; i < Math.min(expected_size, output_size); i++) {
    result &= output[i] == expected[i];
  }
  var rightTick = "\u2713";
  var wrongTick = "\u2717";
  if (result) {
    var out = rightTick + " Test #" + test_case_number;
    console.log(out);
  } else {
    var out = "";
    out += wrongTick + " Test #" + test_case_number + ": Expected ";
    out += printintegerArray(expected);
    out += " Your output: ";
    out += printintegerArray(output);
    console.log(out);
  }
  test_case_number++;
}

var arr_1 = [2, 1];
var expected_1 = [2, 2];
var output_1 = findSignatureCounts(arr_1);
check(expected_1, output_1);

var arr_2 = [1, 2];
var expected_2 = [1, 1];
var output_2 = findSignatureCounts(arr_2);
check(expected_2, output_2);

// Add your own test cases here
