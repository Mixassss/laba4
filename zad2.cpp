// VAR 8 
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <Windows.h>

using namespace std;

vector<int> generateArray(int n, int minChis, int maxChis) { // Функция для генерации случайного массива >= 10
    vector<int> arr(n);
    for (int &num : arr) {
        num = minChis + rand() % (maxChis - minChis + 1);
    }
    return arr;
}

int findMinIndex(vector<int> &arr) { // Функция для нахождения индекса минимального элемента
    return min_element(arr.begin(), arr.end()) - arr.begin();
}

int findMaxSecondIndex(vector<int> &arr) { // Функция для нахождения индекса второго максимального элемента
    int maxVal = *std::max_element(arr.begin(), arr.end());
        int secondMaxIndex = -1;
        bool found = false;
        for (size_t i = 0; i < arr.size(); ++i) { // Условия для поиска второго максимального элемента
            if (arr[i] < maxVal) {
                if (!found || arr[i] > arr[secondMaxIndex]) {
                    secondMaxIndex = i;
                    found = true;
                }
            }
        }
    return secondMaxIndex;
}

void modArray(vector<int> &arr) { // Функция для модификации массива
    if (!arr.empty()) { // Проверка если массив не пустой
        int first = arr[0];
        arr.erase(arr.begin());
        arr.push_back(first);
    }
}

void printArray(vector<int> &arr ,int N) { // Функция для вывода массива
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) { // Массив должен быть не меньше 10
            cout << setw(3) << arr[i * 10 + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand(time(0)); // Инициализируем генератор случайных чисел

    int n; // Генерация массива
    cout << "Введите размер массива (n >= 10): ";
    cin >> n;
    if (n < 10) { // Проверка размера массива
        cerr << "Ошибка! Размер массива не удовлетворяет условию!" << endl;
        return 1;
    }

    vector<int> arr = generateArray(n, 0, 100);
    cout << "Исходный массив: " << endl;
    for (int num : arr) cout << num << " "; // Вывод массива
    cout << endl;

    int minIndex = findMinIndex(arr);
    int secMaxIndex = findMaxSecondIndex(arr);
    if (secMaxIndex != -1) { // Обмен минимального и второго максимального элементов
        swap(arr[minIndex], arr[secMaxIndex]);
    }

    cout << "Массив после изменения: " << endl;
    for (int num : arr) cout << num << " "; // Вывод измененного массива
    cout << endl;

    modArray(arr); // Модификация массива

    cout << "Массив после модификации: " << endl;
    for (int num : arr) cout << num << " "; // Вывод модифицированного массива
    cout << endl;

    int N; // Количество строк
    cout << "Введите количество строк для вывода массива формата N x 10: ";
    cin >> N;
    if (N <= 0) {
        cerr << "Ошибка! Количество строк N должно быть положительным числом!";
        return 1;
    }
    vector<int> outputArray(N * 10);
    for (int i = 0; i < N * 10; ++i) {
        outputArray[i] = 10 + i;
    }

    cout << "Вывод массива (" << N << " x 10):\n";
    printArray(outputArray, N);

    return 0;
}

