def shift(values, k):
    if not values:
        return []

    k %= len(values)

    if k == 0:
        return values.copy()

    return values[-k:] + values[:-k]


def main():
    n = int(input("Введите размер массива: "))

    if n <= 0:
        print("Некорректный размер")
        return

    values = list(map(int, input("Введите элементы массива: ").split()))

    if len(values) != n:
        print("Количество элементов не соответствует размеру массива")
        return

    k = int(input("Введите величину сдвига: "))

    if k <= 0:
        print("k должно быть больше 0")
        return

    print("Результат:")
    print(*shift(values, k))


if __name__ == "__main__":
    main()
