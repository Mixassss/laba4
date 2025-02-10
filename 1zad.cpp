#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <Windows.h>
using namespace std;
const double E = 0.0001;
//?? ????( ?? + 1) = 1
// ������� ��� ������� �������� ��������� ���������
double f(double x) {
	return (2 * x) + cos(x) - 0;
}

// ������� ��� ������� ����������� �������� �������
double f1(double x) {
	return 2 - sin(x) - 0;// ??
}

//������� ����������� �������
int halfDivision(double a, double b, vector<double>& roots) {
	if (f(a) * f(b) >= 0.0) {
		cout << "�������� ��������" << endl;
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
	cout << "������ " << c << " � " << k << " ����������" << endl;
	return k;
}
//����� �������
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
	cout << "������ " << x0 << " � " << k << " ����������" << endl;
	return k;
}
//������ ������� ��������
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
	cout << "������ " << x0 << " � " << k << " ����������" << endl;
	return k;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "��������� ��������� ����� ������� ����������� ������� � ��������� �� E" << endl;
	vector<double> roots;
	int s1 = halfDivision(-1, 1, roots);
	cout << endl << "��������� ��������� ����� �������� � ��������� �� E" << endl;
	int s2 = newtonMethod(10, roots);
	cout << endl << "������ ������� ��������" << endl;
	int s3 = simpleIterations(2, roots);
	cout << endl << "��� ����� ���������" << endl;
	for (double i : roots) {
		cout << i << " ";
	}
	cout << endl << "�������� ����������: " << endl;
	cout << endl << "� ������� �������� " << s2 << endl;
	cout << endl << "� ������ ������� ��������  " << s3 <<  endl;
	cout << endl << "�  ������� ����������� ������� " << s1 << endl;
}
