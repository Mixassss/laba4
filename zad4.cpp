#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

// ���� ������
const bool COOPERATE = true;
const bool BETRAY = false;

// ������� �����
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

// �������� 1: ������ ������������
bool alwaysCooperate(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
    return COOPERATE;
}

// �������� 2: ������ ���������
bool alwaysBetray(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
    return BETRAY;
}

// �������� 3: ��������� ����� ���������� �� �������� ������)
bool titForTat(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
    if (round_number == 0) {
        return COOPERATE; // ������ ��� ������ ��������������
    }
    return enemy_choices.back();
}

// ������ ���� ����� ����� �����������
void playGame(bool (*algorithmA)(int, const vector<bool>&, const vector<bool>&),
              bool (*algorithmB)(int, const vector<bool>&, const vector<bool>&)) {
    int rounds = 100 + rand() % 101; // ���������� ������� �� 100 �� 200
    vector<bool> choicesA, choicesB;
    int scoreA = 0, scoreB = 0;

    cout << "���� ��������! ���������� �������: " << rounds << endl;

    for (int i = 0; i < rounds; ++i) {
        // ��������� ������ ����� ����������
        bool choiceA = algorithmA(i, choicesA, choicesB);
        bool choiceB = algorithmB(i, choicesB, choicesA);

        // ���������� �������
        choicesA.push_back(choiceA);
        choicesB.push_back(choiceB);

        // ������� �����
        auto scores = calculateScores(choiceA, choiceB);
        scoreA += scores.first;
        scoreB += scores.second;

        cout << "����� " << i + 1 << ": A ������ " << (choiceA ? "��������������" : "�������������")
             << ", B ������ " << (choiceB ? "��������������" : "�������������") << endl;
    }

    cout << "���� ��������!" << endl;
    cout << "�������� ����: A = " << scoreA << ", B = " << scoreB << endl;
}

// ������������ ����������
int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand(time(0)); // ������������� ���������� ��������� �����

    // ������ ���
    cout << "���� 1: ������ ������������ vs ������ �������" << endl;
    playGame(alwaysCooperate, alwaysBetray);

    cout << "\n���� 2: ������ ������� vs ��������� ����� ����������" << endl;
    playGame(alwaysBetray, titForTat);

    cout << "\n���� 3: ��������� ����� ���������� vs ������ ������������" << endl;
    playGame(titForTat, alwaysCooperate);

    return 0;
}
