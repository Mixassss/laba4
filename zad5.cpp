#include <iostream>
#include <Windows.h>
#include <random>
#include <vector>
using namespace std;
//Инициализация таблиц
void initialize(int* S, int* K, int s) {
    for (int i = 0; i < s; i++) {
        S[i] = i;
    }
    int j = 0;
    for (int i = 0; i < s; i++) {
        j = (j + S[i] + K[i]) % s;
        swap(S[i], S[j]);
    }
}
// Алгоритм псевдослучайной генерации
void generationAlgorithm(int* S, vector<int>& output, int n) {
    int i = 0;
    int j = 0;
    for (int k = 0; k < n; k++) {
        i = (i + 1) % n;
        j = (j + S[i]) % n;
        swap(S[i], S[j]);
        int t = (S[i] + S[j]) % n;
        int K = S[t];
        output.push_back(K);
    }
}

int main() {
    system ("chcp 65001");
    //2^i
	const int n=32;
	int S[n];
	// Значения ключа K
	int K[n];
    // Заполнение ключа K
    for (int i = 0; i < n;i++) {
        K[i] = i;
    }
    //Инициализация таблиц
    initialize(S, K, n);

    // Алгоритм псевдослучайной генерации
    vector<int> output;
    generationAlgorithm(S, output, n);

    // Вывод сгенерированных чисел
    cout << "Сгенерированные числа: "<<endl;
    for (int i = 0; i<output.size(); i++) {
        cout << i+1 << ": " << output[i] << endl;
    }
    return 0;
}
