#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

int main() {
int N;
cout << "Введите N: ";
cin >> N;

vector<int> array(N * 10); // Создаем массив длиной N * 10

// Заполняем массив последовательными числами, начиная с 10
for (int i = 0; i < N * 10; ++i) {
array[i] = 10 + i;
}

// Вывод массива по 10 элементов в строке
for (int i = 0; i < N * 10; ++i) {
    cout << array[i] << " ";
    if ((i + 1) % 10 == 0) {
        cout << endl;
        }
    }
    system("chcp 65001");
const int n = 15; // Размер массива (не менее 10)
vector<int> numbers(n);

// Генерация случайных чисел и заполнение массива
random_device rd;
    ranlux48 engine(rd());
    uniform_int_distribution<int> dist(1, 100);
for (int i = 0; i < n; ++i) {
numbers[i] = dist(engine);
}

// Вывод исходного массива
cout << "Исходный массив: ";
for (int num : numbers) {
cout << num << " " << endl;
}

// Поиск минимального и второго максимального элемента
int min_index = min_element(numbers.begin(), numbers.end()) - numbers.begin();
int max_index = max_element(numbers.begin(), numbers.end()) - numbers.begin();

// Находим второй максимальный элемент, исключая первый
int second_max_index = min_index; // Инициализируем индексом минимального (на случай, если все элементы равны)
for (int i = 0; i < n; ++i) {
if (numbers[i] > numbers[second_max_index] && i != max_index) {
second_max_index = i;
}
}

// Меняем местами минимальный и второй максимальный элементы
swap(numbers[min_index], numbers[second_max_index]);

// Вывод измененного массива
cout << "Измененный массив: ";
for (int num : numbers) {
cout << num << " ";
}
cout << endl;

return 0;
}
