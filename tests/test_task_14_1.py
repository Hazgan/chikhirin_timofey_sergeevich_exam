from task_14_1 import read_numbers, sum_numbers, write_numbers


def test_write_and_read_numbers(tmp_path):
    file_path = tmp_path / "numbers.txt"
    numbers = [10, -5, 2.5, 7]
    write_numbers(numbers, file_path)
    assert read_numbers(file_path) == [10.0, -5.0, 2.5, 7.0]


def test_sum_numbers(tmp_path):
    file_path = tmp_path / "numbers.txt"
    numbers = [10, -5, 2.5, 7]
    write_numbers(numbers, file_path)
    assert sum_numbers(file_path) == 14.5


def test_empty_file_sum(tmp_path):
    file_path = tmp_path / "numbers.txt"
    file_path.write_text("", encoding="utf-8")
    assert sum_numbers(file_path) == 0.0
