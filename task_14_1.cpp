#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

void writeNumbers(const string& filename, const double* numbers, size_t count) {
    ofstream file(filename);
    if (!file) {
        throw runtime_error("Не удалось открыть файл для записи");
    }

    for (size_t i = 0; i < count; ++i) {
        file << numbers[i] << '\n';
    }
}

void printNumbers(const string& filename, ostream& output) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Не удалось открыть файл для чтения");
    }

    double value;
    while (file >> value) {
        output << value << ' ';
    }
    output << '\n';
}

double sumNumbers(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Не удалось открыть файл для чтения");
    }

    double sum = 0.0;
    double value;
    while (file >> value) {
        sum += value;
    }

    return sum;
}

#ifndef UNIT_TEST
int main() {
    const string filename = "numbers.txt";
    int choice;

    do {
        cout << "\n1. Ввести числа и записать в файл\n";
        cout << "2. Прочитать и вывести числа из файла\n";
        cout << "3. Вычислить сумму всех чисел\n";
        cout << "0. Выход\n";
        cout << "Выберите режим: ";
        cin >> choice;

        try {
            if (choice == 1) {
                size_t count;
                cout << "Количество чисел: ";
                cin >> count;

                double* numbers = new double[count];
                cout << "Введите числа: ";
                for (size_t i = 0; i < count; ++i) {
                    cin >> numbers[i];
                }

                writeNumbers(filename, numbers, count);
                delete[] numbers;
                cout << "Данные записаны в " << filename << '\n';
            } else if (choice == 2) {
                cout << "Числа из файла: ";
                printNumbers(filename, cout);
            } else if (choice == 3) {
                cout << "Сумма: " << sumNumbers(filename) << '\n';
            } else if (choice != 0) {
                cout << "Неизвестный режим\n";
            }
        } catch (const exception& error) {
            cerr << error.what() << '\n';
        }
    } while (choice != 0);

    return 0;
}
#endif
