from pathlib import Path


FILE_NAME = Path("numbers.txt")


def write_numbers(numbers, file_path=FILE_NAME):
    with open(file_path, "w", encoding="utf-8") as file:
        for number in numbers:
            file.write(f"{number}\n")


def read_numbers(file_path=FILE_NAME):
    with open(file_path, "r", encoding="utf-8") as file:
        return [float(line.strip()) for line in file if line.strip()]


def sum_numbers(file_path=FILE_NAME):
    total = 0.0

    with open(file_path, "r", encoding="utf-8") as file:
        for line in file:
            if line.strip():
                total += float(line.strip())

    return total


def main():
    while True:
        print("\n1. Записать числа в файл")
        print("2. Вывести числа из файла")
        print("3. Найти сумму чисел")
        print("0. Выход")

        choice = input("Выберите действие: ").strip()

        try:
            if choice == "1":
                count = int(input("Количество чисел: "))
                numbers = []
                print("Введите числа:")

                for _ in range(count):
                    numbers.append(float(input()))

                write_numbers(numbers)
                print("Числа записаны")

            elif choice == "2":
                print("Числа в файле:")
                print(*read_numbers())

            elif choice == "3":
                print(f"Сумма: {sum_numbers()}")

            elif choice == "0":
                break

            else:
                print("Неизвестная команда")

        except FileNotFoundError:
            print("Файл numbers.txt не найден")
        except ValueError:
            print("Ошибка: требуется числовое значение")


if __name__ == "__main__":
    main()
