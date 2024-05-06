#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;

int generateRandomNumber() {
    random_device rd;
    ranlux48 engine(rd());
    uniform_int_distribution<int> dist(1, 100); // Задавать диапазон для генерации чисел
    return dist(engine);
}

void fillArray(vector<int>& arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr.push_back(generateRandomNumber());
    }
}

double chiSquareTest(const vector<int>& observed, const vector<int>& expected) {
    double chiSquare = 0.0;
    for (size_t i = 0; i < observed.size(); ++i) {
        chiSquare += pow(observed[i] - expected[i], 2) / expected[i];
    }
    return chiSquare;
}

bool hypothesisTest(double chiSquare, double criticalValue) {
    return chiSquare > criticalValue;
}

vector<int> calculateExpected(const vector<int>& observed) {
    vector<int> expected(observed.size(), 50); // В данном случае просто задаем ожидаемое значение как 50 для каждого элемента
    return expected;
}

int main() {
    system("chcp 65001");
    vector<int> array50, array100, array1000;
    fillArray(array50, 50);
    fillArray(array100, 100);
    fillArray(array1000, 1000);
    double criticalValue = 100;

    vector<int> expected = calculateExpected(array1000);
    double chiSquare = chiSquareTest(array1000, expected);

    bool hypothesisResult = hypothesisTest(chiSquare, criticalValue);

    cout << "Результат проверки гипотезы: " << (hypothesisResult ? "Отклонить" : "Принять") << endl;
    cout << "Ожидаемое математическое ожидание: " << expected[0] << endl;
    double realMean = accumulate(array100.begin(), array100.end(), 0) / static_cast<double>(array100.size());
    cout << "Реальное математическое ожидание: " << realMean << endl;

    return 0;
}
