def shift(values, k):
    if not values:
        return []

    k %= len(values)

    if k == 0:
        return values.copy()

    return values[-k:] + values[:-k]


def main():
    values = list(map(int, input("Введите элементы массива через пробел: ").split()))

    k = int(input("Введите величину сдвига: "))

    if k <= 0:
        print("k должно быть больше 0")
        return

    print("Результат:")
    print(*shift(values, k))


if __name__ == "__main__":
    main()
