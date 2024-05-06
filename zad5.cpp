#include <iostream>
using namespace std;

class BBSGenerator {
private:
    unsigned long p, q, M, seed;

public:
    BBSGenerator(unsigned long pValue, unsigned long qValue, unsigned long initialSeed) : p(pValue), q(qValue), seed(initialSeed) {
        M = p * q;
    }

    unsigned long generateRandomNumber() {
        seed = (seed * seed) % M;
        return seed;
    }
};

int main() {
    unsigned long pValue = 19, qValue = 23; // Простые числа p и q
    unsigned long initialValue = 7; // Начальное значение для генератора

    BBSGenerator bbs(pValue, qValue, initialValue);

    // Генерация псевдослучайных чисел
    cout << bbs.generateRandomNumber() << " ";
    cout << bbs.generateRandomNumber() << " ";
    cout << bbs.generateRandomNumber() << " ";
    cout << bbs.generateRandomNumber() << " ";
    cout << bbs.generateRandomNumber() << endl;

    return 0;
}
