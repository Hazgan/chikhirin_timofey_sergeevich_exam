#include <cassert>
#include <iostream>
#include <stdexcept>

#define UNIT_TEST
#include "../task_16_4.cpp"

int main() {
    Time first(10, 20, 30);
    Time second(11, 21, 40);

    assert(first.toString() == "10:20:30");
    assert(first.differenceInSeconds(second) == 3670);
    assert(first.addSeconds(90).toString() == "10:22:00");
    assert(first.addMinutes(60).toString() == "11:20:30");
    assert(Time(23, 59, 30).addSeconds(60).toString() == "00:00:30");
    assert(Time(0, 0, 30).addSeconds(-60).toString() == "23:59:30");

    bool exceptionThrown = false;
    try {
        Time invalid(25, 0, 0);
    } catch (const invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    cout << "test_16_4: OK\n";
    return 0;
}
