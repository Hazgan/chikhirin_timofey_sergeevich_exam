#include <cassert>
#include <iostream>
#include <vector>

#define UNIT_TEST
#include "../task_7_7.cpp"

int main() {
    vector<int> first = {1, 2, 3, 4, 5};
    cyclicShiftRight(first, 2);
    assert((first == vector<int>{4, 5, 1, 2, 3}));

    vector<int> second = {1, 2, 3, 4, 5};
    cyclicShiftRight(second, 7);
    assert((second == vector<int>{4, 5, 1, 2, 3}));

    vector<int> third = {1, 2, 3};
    cyclicShiftRight(third, 3);
    assert((third == vector<int>{1, 2, 3}));

    vector<int> empty;
    cyclicShiftRight(empty, 5);
    assert(empty.empty());

    cout << "test_7_7: OK\n";
    return 0;
}
