#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

bool func(int round_number, vector<bool>& self_choices, vector<bool>& enemy_choices) {
    // код для алгоритма
    if (round_number == 0) {
        return true; // В начале игры всегда сотрудничаем
    } else {
        // Расчет стратегии алгоритма на основе предыдущих раундов
        int total_rounds = self_choices.size();
        int self_cooperate_count = 0, enemy_cooperate_count = 0;

        for (int i = 0; i < total_rounds; ++i) {
            if (self_choices[i] == true) {
                self_cooperate_count++;
            }
            if (enemy_choices[i] == true) {
                enemy_cooperate_count++;
            }
        }

        // Пример простой стратегии: если противник предал на предыдущем раунде, тогда предаем, иначе сотрудничаем
        if (enemy_choices[round_number - 1] == false) {
            return false;
        } else {
            return true;
        }
    }
}

int main() {
    srand(time(0));

    int num_rounds = rand() % 101 + 100; // Генерация случайного количества раундов от 100 до 200
    vector<bool> self_choices;
    vector<bool> enemy_choices;

    for (int i = 0; i < num_rounds; ++i) {
        self_choices.push_back(func(i, self_choices, enemy_choices));
        enemy_choices.push_back(rand() % 2); // Генерация случайного выбора противника: 0 - предательство, 1 - сотрудничество
    }

    // Вывод результатов
    for (int i = 0; i < num_rounds; ++i) {
        cout << "Раунд " << i << ": ";
        if (self_choices[i] && enemy_choices[i]) {
            cout << "Оба сотрудничают. Каждый получает 24 очка.\n";
        } else if (!self_choices[i] && !enemy_choices[i]) {
            cout << "Оба предали. Каждый получает 4 очка.\n";
        } else if (self_choices[i] && !enemy_choices[i]) {
            cout << "Алгоритм А сотрудничает, алгоритм Б предал. А: 0 очков, Б: 20 очков.\n";
        } else {
            cout << "Алгоритм А предал, алгоритм Б сотрудничает. А: 20 очков, Б: 0 очков.\n";
        }
    }

    return 0;
}
