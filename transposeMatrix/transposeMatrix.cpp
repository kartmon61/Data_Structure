#include<iostream>

using namespace std;

int main() {
	int A[100][100];
	int B[100][3];
	int m, n = 0;
	int cnt = 0;

	//m X n 행렬을 만든다.
	cout << "sparse Matrix를 만들 (m) X (n) 행렬을 순서대로 입력하세요: \n";
	cin >> m >> n;
	cout << "\nsparse Matrix를 만들 행렬 값을 입력하세요.(값의 대부분은 0)\n";

	//행렬의 값을 입력한다 ( 대부분의 값이 0이여야 한다. )
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "\n" << i << " 행 " << j << "열:  ";
			cin >> A[i][j];
			if (A[i][j] != 0) cnt++;
		}
	}

	//입력한 행렬을 출력한다.
	cout << "\n 입력한 행렬은 : \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}

	//sparseMatrix 만들기
	int s = 1;
	//첫 행에서는 행,열,0이 아닌 값의 개수 입력
	B[0][0] = m;
	B[0][1] = n;
	B[0][2] = cnt;
	//0이 아닌 값을 Sparse Matrix
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

	//Sparse Matrix 출력하기
	cout << "\n\n Sparse Matrix는\n";
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < 3; j++) {
			cout << B[i][j] << " ";
		}
		cout << "\n";
	}




	//A의 배열 0으로 초기화
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}

	int temp = 0;
	int row = 0;
	int col = 0;
	//Sparse Matrix를 이용하여 Transpose
	for (int i = 1; i < s; i++) {
		//열과 행 바꾸기
		temp = B[i][0];
		B[i][0] = B[i][1];
		B[i][1] = temp;
		//행과 열에 해당하는 값을 A에 저장
		row = B[i][0];
		col = B[i][1];
		A[row][col] = B[i][2];
		B[i][2] = 0;
	}
	//Transpose Matrix 출력
	cout << "\n Transpose Matrix는 \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}