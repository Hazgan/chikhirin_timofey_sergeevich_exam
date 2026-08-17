class Time:
    SECONDS_PER_DAY = 24 * 60 * 60

    def __init__(self, hours=0, minutes=0, seconds=0):
        total = hours * 3600 + minutes * 60 + seconds
        self._set_from_seconds(total)

    def _set_from_seconds(self, total):
        total %= self.SECONDS_PER_DAY
        self.hours = total // 3600
        self.minutes = (total % 3600) // 60
        self.seconds = total % 60

    def to_seconds(self):
        return self.hours * 3600 + self.minutes * 60 + self.seconds

    def difference_in_seconds(self, other):
        return abs(self.to_seconds() - other.to_seconds())

    def add_seconds(self, value):
        return Time(seconds=self.to_seconds() + value)

    def add_minutes(self, value):
        return self.add_seconds(value * 60)

    def __str__(self):
        return f"{self.hours:02d}:{self.minutes:02d}:{self.seconds:02d}"


def main():
    h1, m1, s1 = map(int, input("Введите первое время (часы минуты секунды): ").split())
    h2, m2, s2 = map(int, input("Введите второе время (часы минуты секунды): ").split())

    first = Time(h1, m1, s1)
    second = Time(h2, m2, s2)

    print(f"Разница: {first.difference_in_seconds(second)} секунд")

    seconds = int(input("Сколько секунд прибавить к первому времени: "))
    print(f"Результат: {first.add_seconds(seconds)}")

    minutes = int(input("Сколько минут прибавить к первому времени: "))
    print(f"Результат: {first.add_minutes(minutes)}")


if __name__ == "__main__":
    main()
