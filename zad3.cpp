#include <iostream>
#include <Windows.h>
#include <random>
#include <vector>
using namespace std;
const int n1 = 50, n2 = 100, n3 = 1000;
void generateRandomNumber(int* arr, int n) {
    random_device rd;
    ranlux48 engine(rd());
    uniform_int_distribution<int> dist(1, 100); // Задавать диапазон для генерации чисел
    for (int i = 0; i < n; i++) {
		arr[i] = dist(engine);
	}
}

int X2(int arr[], int n) {
	const int iter = 25;
	int sum[iter] = { 0 };
	int mat = 0;
	for (int i = 0; i < n;i++) {
		//Делим интервалы и подсчитываем колличество в них
		sum[arr[i] * iter / 101]++;
		mat += arr[i];
	}
	float x = 0;
	cout << "Кол-во i элементов в 25 интервалах" << endl;
	for (int i : sum) {
		cout << i << " ";
		// i кол элем в интервалов
		// n1 / iter - ожидаемо
		x += float((i - (n / iter)) * (i - (n / iter))) / (n / iter);
	}
	cout << endl<<"Мат ожидание ожидание: 50,5 реальность: "<<mat/n<<endl;
	return x;
}
int main() {
	system ("chcp 65001");
	int arr1[n1];
	generateRandomNumber(arr1, n1);
	int arr2[n2];
	generateRandomNumber(arr2, n2);
	int arr3[n3];
	generateRandomNumber(arr3, n3);
	float krit = 44.314;
	cout << " Для массива на 50 элементов " << endl;
	//Результат проврки гипотезы 
	int x = X2(arr1, n1);
	cout << " x^2 : " << x<< endl;
	if (x < krit) {
		cout << "Гипотеза о нормальном распределении принимается."<<endl;
	}
	else {
		cout << "Гипотеза о нормальном распределении отклоняется." << endl;
	}
	cout << " Для массива на 100 элементов " << endl;
	x = X2(arr2, n2);
	cout << " x^2 : " << x << endl;
	if (x < krit) {
		cout << "Гипотеза о нормальном распределении принимается." << endl;
	}
	else {
		cout << "Гипотеза о нормальном распределении отклоняется." << endl;
	}
	cout << " Для массива на 1000 элементов " << endl;
	x = X2(arr3, n3);
	cout << " x^2 : " << x << endl;
	if (x < krit) {
		cout << "Гипотеза о нормальном распределении принимается." << endl;
	}
	else {
		cout << "Гипотеза о нормальном распределении отклоняется." << endl;
	}
}
