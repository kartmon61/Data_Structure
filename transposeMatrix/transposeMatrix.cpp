#include<iostream>

using namespace std;

int main() {
	int A[100][100];
	int B[100][3];
	int m, n = 0;
	int cnt = 0;

	//m X n ����� �����.
	cout << "sparse Matrix�� ���� (m) X (n) ����� ������� �Է��ϼ���: \n";
	cin >> m >> n;
	cout << "\nsparse Matrix�� ���� ��� ���� �Է��ϼ���.(���� ��κ��� 0)\n";

	//����� ���� �Է��Ѵ� ( ��κ��� ���� 0�̿��� �Ѵ�. )
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "\n" << i << " �� " << j << "��:  ";
			cin >> A[i][j];
			if (A[i][j] != 0) cnt++;
		}
	}

	//�Է��� ����� ����Ѵ�.
	cout << "\n �Է��� ����� : \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}

	//sparseMatrix �����
	int s = 1;
	//ù �࿡���� ��,��,0�� �ƴ� ���� ���� �Է�
	B[0][0] = m;
	B[0][1] = n;
	B[0][2] = cnt;
	//0�� �ƴ� ���� Sparse Matrix
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] != 0) {
				B[s][0] = i;
				B[s][1] = j;
				B[s][2] = A[i][j];
				s++;
			}
		}
	}

	//Sparse Matrix ����ϱ�
	cout << "\n\n Sparse Matrix��\n";
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < 3; j++) {
			cout << B[i][j] << " ";
		}
		cout << "\n";
	}




	//A�� �迭 0���� �ʱ�ȭ
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}

	int temp = 0;
	int row = 0;
	int col = 0;
	//Sparse Matrix�� �̿��Ͽ� Transpose
	for (int i = 1; i < s; i++) {
		//���� �� �ٲٱ�
		temp = B[i][0];
		B[i][0] = B[i][1];
		B[i][1] = temp;
		//��� ���� �ش��ϴ� ���� A�� ����
		row = B[i][0];
		col = B[i][1];
		A[row][col] = B[i][2];
		B[i][2] = 0;
	}
	//Transpose Matrix ���
	cout << "\n Transpose Matrix�� \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}