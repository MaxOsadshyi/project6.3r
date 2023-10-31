#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

// Функція для створення та заповнення масиву випадковими числами
void createArray(vector<int>& array, int size) {
    array.resize(size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 - 50;  // Генерувати випадкові числа від -50 до 49
    }
}

// Функція для виведення масиву на екран у вигляді рядка
void printArray(const vector<int>& array) {
    for (int num : array) {
        cout << num << ' ';
    }
    cout << endl;
}

// Рекурсивна функція для обчислення кількості додатних елементів масиву
int countPositiveElements(const vector<int>& array, int index) {
    if (index < array.size()) {
        if (array[index] > 0) {
            return 1 + countPositiveElements(array, index + 1);
        }
        else {
            return countPositiveElements(array, index + 1);
        }
    }
    return 0;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(static_cast<unsigned>(time(nullptr)));

    int arraySize;
    cout << "Введіть розмір масиву: ";
    cin >> arraySize;

    vector<int> arr;
    createArray(arr, arraySize);

    cout << "Згенерований масив: ";
    printArray(arr);

    // Рекурсивний спосіб для обчислення кількості додатних елементів
    int positiveCount = countPositiveElements(arr, 0);
    cout << "Кількість додатних елементів (рекурсивний спосіб): " << positiveCount << endl;

    return 0;
}
