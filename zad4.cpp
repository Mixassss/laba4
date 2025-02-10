#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

// Типы выбора
const bool COOPERATE = true;
const bool BETRAY = false;

// Подсчет очков
pair<int, int> calculateScores(bool choiceA, bool choiceB) {
    if (choiceA == COOPERATE && choiceB == COOPERATE) {
        return {24, 24};
    } else if (choiceA == COOPERATE && choiceB == BETRAY) {
        return {0, 20};
    } else if (choiceA == BETRAY && choiceB == COOPERATE) {
        return {20, 0};
    } else { // BETRAY && BETRAY
        return {4, 4};
    }
}

// Алгоритм 1: Всегда сотрудничать
bool alwaysCooperate(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
    return COOPERATE;
}

// Алгоритм 2: Всегда предавать
bool alwaysBetray(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
    return BETRAY;
}

// Алгоритм 3: Повторяет выбор противника из прошлого раунда)
bool titForTat(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
    if (round_number == 0) {
        return COOPERATE; // Первый ход всегда сотрудничество
    }
    return enemy_choices.back();
}

// Запуск игры между двумя алгоритмами
void playGame(bool (*algorithmA)(int, const vector<bool>&, const vector<bool>&),
              bool (*algorithmB)(int, const vector<bool>&, const vector<bool>&)) {
    int rounds = 100 + rand() % 101; // Количество раундов от 100 до 200
    vector<bool> choicesA, choicesB;
    int scoreA = 0, scoreB = 0;

    cout << "Игра началась! Количество раундов: " << rounds << endl;

    for (int i = 0; i < rounds; ++i) {
        // Получение выбора обоих алгоритмов
        bool choiceA = algorithmA(i, choicesA, choicesB);
        bool choiceB = algorithmB(i, choicesB, choicesA);

        // Сохранение выборов
        choicesA.push_back(choiceA);
        choicesB.push_back(choiceB);

        // Подсчет очков
        auto scores = calculateScores(choiceA, choiceB);
        scoreA += scores.first;
        scoreB += scores.second;

        cout << "Раунд " << i + 1 << ": A выбрал " << (choiceA ? "Сотрудничество" : "Предательство")
             << ", B выбрал " << (choiceB ? "Сотрудничество" : "Предательство") << endl;
    }

    cout << "Игра окончена!" << endl;
    cout << "Итоговый счет: A = " << scoreA << ", B = " << scoreB << endl;
}

// Тестирование алгоритмов
int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand(time(0)); // Инициализация генератора случайных чисел

    // Запуск игр
    cout << "Игра 1: Всегда сотрудничает vs Всегда предает" << endl;
    playGame(alwaysCooperate, alwaysBetray);

    cout << "\nИгра 2: Всегда предает vs Повторяет выбор противника" << endl;
    playGame(alwaysBetray, titForTat);

    cout << "\nИгра 3: Повторяет выбор противника vs Всегда сотрудничает" << endl;
    playGame(titForTat, alwaysCooperate);

    return 0;
}
