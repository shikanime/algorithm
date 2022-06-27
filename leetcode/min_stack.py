class MinStack:
    data: list[int]
    min: list[int]

    def __init__(self):
        self.data = []
        self.min = []

    def push(self, val: int) -> None:
        self.data.append(val)
        self.min.append(min(val, self.min[-1] if len(self.min) != 0 else val))

    def pop(self) -> None:
        self.data.pop()
        self.min.pop()

    def top(self) -> int:
        return self.data[-1]

    def getMin(self) -> int:
        return self.min[-1]
