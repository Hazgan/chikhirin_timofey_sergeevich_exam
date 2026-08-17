#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

#define UNIT_TEST
#include "../task_14_1.cpp"

int main() {
    const string filename = "test_numbers.txt";
    const double numbers[] = {1.5, -2.0, 3.25, 7.25};

    writeNumbers(filename, numbers, 4);

    double sum = sumNumbers(filename);
    assert(fabs(sum - 10.0) < 1e-9);

    ostringstream output;
    printNumbers(filename, output);
    assert(output.str() == "1.5 -2 3.25 7.25 \n");

    remove(filename.c_str());

    cout << "test_14_1: OK\n";
    return 0;
}
