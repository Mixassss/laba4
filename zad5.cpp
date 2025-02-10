#include <iostream>
#include <Windows.h>
#include <random>
#include <vector>
using namespace std;
//������������� ������
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
// �������� ��������������� ���������
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
	// �������� ����� K
	int K[n];
    // ���������� ����� K
    for (int i = 0; i < n;i++) {
        K[i] = i;
    }
    //������������� ������
    initialize(S, K, n);

    // �������� ��������������� ���������
    vector<int> output;
    generationAlgorithm(S, output, n);

    // ����� ��������������� �����
    cout << "��������������� �����: "<<endl;
    for (int i = 0; i<output.size(); i++) {
        cout << i+1 << ": " << output[i] << endl;
    }
    return 0;
}
