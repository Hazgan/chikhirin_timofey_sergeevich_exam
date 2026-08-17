from task_7_7 import cyclic_shift_right


def test_shift_by_two():
    assert cyclic_shift_right([1, 2, 3, 4, 5], 2) == [4, 5, 1, 2, 3]


def test_shift_greater_than_length():
    assert cyclic_shift_right([1, 2, 3, 4, 5], 7) == [4, 5, 1, 2, 3]


def test_shift_by_length():
    assert cyclic_shift_right([1, 2, 3], 3) == [1, 2, 3]


def test_empty_list():
    assert cyclic_shift_right([], 5) == []
