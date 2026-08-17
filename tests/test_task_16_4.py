from task_16_4 import Time


def test_difference_in_seconds():
    first = Time(10, 20, 30)
    second = Time(11, 21, 40)
    assert first.difference_in_seconds(second) == 3670


def test_add_seconds():
    value = Time(10, 20, 30)
    assert str(value.add_seconds(5000)) == "11:43:50"


def test_add_minutes():
    value = Time(10, 20, 30)
    assert str(value.add_minutes(90)) == "11:50:30"


def test_day_wrap():
    value = Time(23, 59, 30)
    assert str(value.add_seconds(90)) == "00:01:00"
