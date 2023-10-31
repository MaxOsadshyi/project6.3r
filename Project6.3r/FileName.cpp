#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

// ������� ��� ��������� �� ���������� ������ ����������� �������
void createArray(vector<int>& array, int size) {
    array.resize(size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 - 50;  // ���������� �������� ����� �� -50 �� 49
    }
}

// ������� ��� ��������� ������ �� ����� � ������ �����
void printArray(const vector<int>& array) {
    for (int num : array) {
        cout << num << ' ';
    }
    cout << endl;
}

// ���������� ������� ��� ���������� ������� �������� �������� ������
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
    cout << "������ ����� ������: ";
    cin >> arraySize;

    vector<int> arr;
    createArray(arr, arraySize);

    cout << "������������ �����: ";
    printArray(arr);

    // ����������� ����� ��� ���������� ������� �������� ��������
    int positiveCount = countPositiveElements(arr, 0);
    cout << "ʳ������ �������� �������� (����������� �����): " << positiveCount << endl;

    return 0;
}
