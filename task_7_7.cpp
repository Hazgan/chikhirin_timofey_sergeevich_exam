#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

void cyclicShiftRight(vector<int>& values, size_t k) {
    if (values.empty()) {
        return;
    }

    k %= values.size();
    if (k == 0) {
        return;
    }

    reverse(values.begin(), values.end());
    reverse(values.begin(), values.begin() + static_cast<long long>(k));
    reverse(values.begin() + static_cast<long long>(k), values.end());
}

#ifndef UNIT_TEST
int main() {
    size_t n;
    cout << "Введите размер массива: ";
    cin >> n;

    if (n == 0) {
        cerr << "Размер массива должен быть больше нуля\n";
        return 1;
    }

    vector<int> values(n);
    cout << "Введите элементы массива: ";
    for (int& value : values) {
        cin >> value;
    }

    size_t k;
    cout << "Введите k: ";
    cin >> k;

    if (k == 0) {
        cerr << "k должно быть больше нуля\n";
        return 1;
    }

    cyclicShiftRight(values, k);

    cout << "Результат: ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}
#endif
