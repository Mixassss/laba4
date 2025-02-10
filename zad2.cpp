// VAR 8 
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <Windows.h>

using namespace std;

vector<int> generateArray(int n, int minChis, int maxChis) { // ������� ��� ��������� ���������� ������� >= 10
    vector<int> arr(n);
    for (int &num : arr) {
        num = minChis + rand() % (maxChis - minChis + 1);
    }
    return arr;
}

int findMinIndex(vector<int> &arr) { // ������� ��� ���������� ������� ������������ ��������
    return min_element(arr.begin(), arr.end()) - arr.begin();
}

int findMaxSecondIndex(vector<int> &arr) { // ������� ��� ���������� ������� ������� ������������� ��������
    int maxVal = *std::max_element(arr.begin(), arr.end());
        int secondMaxIndex = -1;
        bool found = false;
        for (size_t i = 0; i < arr.size(); ++i) { // ������� ��� ������ ������� ������������� ��������
            if (arr[i] < maxVal) {
                if (!found || arr[i] > arr[secondMaxIndex]) {
                    secondMaxIndex = i;
                    found = true;
                }
            }
        }
    return secondMaxIndex;
}

void modArray(vector<int> &arr) { // ������� ��� ����������� �������
    if (!arr.empty()) { // �������� ���� ������ �� ������
        int first = arr[0];
        arr.erase(arr.begin());
        arr.push_back(first);
    }
}

void printArray(vector<int> &arr ,int N) { // ������� ��� ������ �������
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) { // ������ ������ ���� �� ������ 10
            cout << setw(3) << arr[i * 10 + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand(time(0)); // �������������� ��������� ��������� �����

    int n; // ��������� �������
    cout << "������� ������ ������� (n >= 10): ";
    cin >> n;
    if (n < 10) { // �������� ������� �������
        cerr << "������! ������ ������� �� ������������� �������!" << endl;
        return 1;
    }

    vector<int> arr = generateArray(n, 0, 100);
    cout << "�������� ������: " << endl;
    for (int num : arr) cout << num << " "; // ����� �������
    cout << endl;

    int minIndex = findMinIndex(arr);
    int secMaxIndex = findMaxSecondIndex(arr);
    if (secMaxIndex != -1) { // ����� ������������ � ������� ������������� ���������
        swap(arr[minIndex], arr[secMaxIndex]);
    }

    cout << "������ ����� ���������: " << endl;
    for (int num : arr) cout << num << " "; // ����� ����������� �������
    cout << endl;

    modArray(arr); // ����������� �������

    cout << "������ ����� �����������: " << endl;
    for (int num : arr) cout << num << " "; // ����� ����������������� �������
    cout << endl;

    int N; // ���������� �����
    cout << "������� ���������� ����� ��� ������ ������� ������� N x 10: ";
    cin >> N;
    if (N <= 0) {
        cerr << "������! ���������� ����� N ������ ���� ������������� ������!";
        return 1;
    }
    vector<int> outputArray(N * 10);
    for (int i = 0; i < N * 10; ++i) {
        outputArray[i] = 10 + i;
    }

    cout << "����� ������� (" << N << " x 10):\n";
    printArray(outputArray, N);

    return 0;
}

