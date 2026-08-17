#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    static long long normalize(long long total) {
        const long long day = 24LL * 60 * 60;
        total %= day;
        if (total < 0) {
            total += day;
        }
        return total;
    }

    void fromSeconds(long long total) {
        total = normalize(total);
        hours = static_cast<int>(total / 3600);
        minutes = static_cast<int>((total % 3600) / 60);
        seconds = static_cast<int>(total % 60);
    }

public:
    Time(int h = 0, int m = 0, int s = 0) {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
            throw invalid_argument("Некорректное время");
        }
        hours = h;
        minutes = m;
        seconds = s;
    }

    long long toSeconds() const {
        return static_cast<long long>(hours) * 3600 + minutes * 60 + seconds;
    }

    long long differenceInSeconds(const Time& other) const {
        return llabs(toSeconds() - other.toSeconds());
    }

    Time addSeconds(long long value) const {
        Time result;
        result.fromSeconds(toSeconds() + value);
        return result;
    }

    Time addMinutes(long long value) const {
        return addSeconds(value * 60);
    }

    string toString() const {
        ostringstream out;
        out << setfill('0') << setw(2) << hours << ':'
            << setw(2) << minutes << ':'
            << setw(2) << seconds;
        return out.str();
    }
};

#ifndef UNIT_TEST
int main() {
    try {
        int h1, m1, s1;
        int h2, m2, s2;

        cout << "Введите первое время (часы минуты секунды): ";
        cin >> h1 >> m1 >> s1;

        cout << "Введите второе время (часы минуты секунды): ";
        cin >> h2 >> m2 >> s2;

        Time first(h1, m1, s1);
        Time second(h2, m2, s2);

        cout << "Разность в секундах: " << first.differenceInSeconds(second) << '\n';

        long long value;
        cout << "На сколько секунд изменить первое время: ";
        cin >> value;
        cout << "Результат: " << first.addSeconds(value).toString() << '\n';

        cout << "На сколько минут изменить первое время: ";
        cin >> value;
        cout << "Результат: " << first.addMinutes(value).toString() << '\n';
    } catch (const exception& error) {
        cerr << error.what() << '\n';
        return 1;
    }

    return 0;
}
#endif
