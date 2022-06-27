from .min_stack import MinStack


def test_min_stack():
    obj = MinStack()
    obj.push(-2)
    assert obj.data == [-2]
    obj.push(0)
    assert obj.data == [-2, 0]
    obj.push(-3)
    assert obj.data == [-2, 0, -3]
    assert obj.getMin() == -3
    obj.pop()
    assert obj.data == [-2, 0]
    assert obj.top() == 0
    assert obj.getMin() == -2
