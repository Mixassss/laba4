#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для расчета значения исходного уравнения
double func(double x) {
    return x * log(x + 1) - 1;
}

// Функция для расчета производной исходной функции
double derivative(double x) {
    return log(x + 1) + x / (x + 1);
}

// Метод Ньютона для решения уравнения
void newtonMethod(double x0, double epsilon) {
    int N = 0;
    double xn = x0, xn1, diff;
    
    cout << fixed << setprecision(6);
    cout << "| N  |    xn    |     xn+1     | xn+1 – xn |\n";
    
    do {
        xn1 = xn - func(xn) / derivative(xn);
        diff = abs(xn1 - xn);
        cout << "| " << N << "  | " << xn << " | " << xn1 << " | " << diff << " |\n";
        xn = xn1;
        N++;
    } while (diff >= epsilon);
    
    cout << "Корень уравнения методом Ньютона: " << xn << endl;
}

// Метод простых итераций для решения уравнения
void simpleIterationMethod(double x0, double epsilon) {
    int N = 0;
    double xn = x0, xn1, diff;
    // Вывод таблицы с результатами иллюстрирующей шаги метода простых итераций
    cout << fixed << setprecision(6);
    cout << "| N  |    xn    |     xn+1     | xn+1 – xn |\n";
    
    do {
         // Применение формулы для метода простых итераций
        xn1 = log(1/xn + 1);
        diff = abs(xn1 - xn);
        cout << "| " << N << "  | " << xn << " | " << xn1 << " | " << diff << " |\n";
        xn = xn1;
        N++;
    } while (diff >= epsilon);
    // Вывод найденного корня уравнения методом простых итераций
    cout << "Корень уравнения методом простых итераций: " << xn << endl;
}

//Метод половинного деления
void bisectionMethod(double a, double b, double epsilon) {
    if (func(a) * func(b) >= 0) {
        cout << "Невозможно найти корень на указанном интервале. Пожалуйста, выберите другие a и b." << endl;
        return;
    }

    int N = 1;
    double an, bn;

    cout << setw(5) << "N" << setw(10) << "an" << setw(10) << "bn" << setw(15) << "bn - an" << endl;

    while ((b - a) >= epsilon) {
        double c = (a + b) / 2;

        if (func(c) == 0.0) {
            break;
        } else if (func(c) * func(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        an = a;
        bn = b;

        cout << setw(5) << N << setw(10) << an << setw(10) << bn << setw(15) << bn - an << endl;

        N++;
    }
    

    cout << "Корень уравнения на заданной точности равен: " << (a + b) / 2 << endl;
}

int main() {
    double a = 0.1; // начальное значение интервала [a, b]
    double b = 2.0; // начальное значение интервала [a, b]
    double x0 = 0.1; // начальное приближение
    double epsilon = 0.0001; // требуемая точность

    bisectionMethod (a, b, epsilon);
    
    newtonMethod (x0, epsilon); // Вызов функции для метода Ньютона
    simpleIterationMethod (x0, epsilon); // Вызов функции для метода простых итераций

    return 0;
}
