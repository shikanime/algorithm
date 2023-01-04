from functools import reduce


class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        return reduce(self.evalToken, tokens, [])[0]

    def evalToken(self, state, token: str):
        if token == "+":
            return state[:-2] + [state[-2] + state[-1]]
        elif token == "-":
            return state[:-2] + [state[-2] - state[-1]]
        elif token == "*":
            return state[:-2] + [state[-2] * state[-1]]
        elif token == "/":
            return state[:-2] + [int(state[-2] / state[-1])]
        return state + [int(token)]
