#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <Windows.h>
using namespace std;
const double E = 0.0001;
//?? ????( ?? + 1) = 1
// Функция для расчета значения исходного уравнения
double f(double x) {
	return (2 * x) + cos(x) - 0;
}

// Функция для расчета производной исходной функции
double f1(double x) {
	return 2 - sin(x) - 0;// ??
}

//методом половинного деления
int halfDivision(double a, double b, vector<double>& roots) {
	if (f(a) * f(b) >= 0.0) {
		cout << "Неверный интервал" << endl;
		return 0;
	}
	int k = 0;
	double c = 0;
	while (abs(b - a) >= E) {
		cout << setw(7) << k << "|" << setw(8) << fixed << setprecision(4) << a << " | " << setw(8) << b << "|" << b - a << endl;
		c = (a + b) / 2;
		if (f(c) == 0.0) {
			break;
		}
		else if (f(c) * f(a) < 0) {
			b = c;
		}
		else {
			a = c;
		}
		k++;
	}
	roots.push_back(c);
	cout << "Корень " << c << " с " << k << " итерациями" << endl;
	return k;
}
//Метод Ньютона
int newtonMethod(double x0, vector<double>& roots) {
	int k = 0;
	double x1 = x0 - f(x0) / f1(x0);
	while (abs(x1 - x0) >= E) {
		cout << setw(7) << k << "|" << setw(8) << fixed << setprecision(4) << x0 << " | " << setw(8) << x1 << "|" << x1 - x0 << endl;
		x0 = x1;
		x1 = x0 - f(x0) / f1(x0);
		k++;
	}
	roots.push_back(x0);
	cout << "Корень " << x0 << " с " << k << " итерациями" << endl;
	return k;
}
//метода простых итераций
int simpleIterations(double x0, vector<double>& roots) {
	int k = 0;
	double x1 = 1 / log(x0 + 1);
	while (abs(x1 - x0) > E) {
		cout << setw(7) << k << "|" << setw(8) << fixed << setprecision(4) << x0 << " | " << setw(8) << x1 << "|" << x1 - x0 << endl;
		x0 = x1;
		x1 = 1 / log(x0 + 1);
		k++;
	}
	roots.push_back(x0);
	cout << "Корень " << x0 << " с " << k << " итерациями" << endl;
	return k;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "программу уточнения корня методом половинного деления с точностью до E" << endl;
	vector<double> roots;
	int s1 = halfDivision(-1, 1, roots);
	cout << endl << "программу уточнения корня Ньютоном с точностью до E" << endl;
	int s2 = newtonMethod(10, roots);
	cout << endl << "метода простых итераций" << endl;
	int s3 = simpleIterations(2, roots);
	cout << endl << "все корни уравнения" << endl;
	for (double i : roots) {
		cout << i << " ";
	}
	cout << endl << "Скорость сходимости: " << endl;
	cout << endl << "У Ньютона итераций " << s2 << endl;
	cout << endl << "У метода простых итераций  " << s3 <<  endl;
	cout << endl << "У  методом половинного деления " << s1 << endl;
}
