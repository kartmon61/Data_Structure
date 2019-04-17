#include<iostream>
#include<random>
#include<ctime>
#include<algorithm>

#define MAX_SIZE 101
using namespace std;

//�� �Լ� ����
int compare(int a, int b) {
	if (a > b) return 1; //a>b �̸� 1 ��ȯ
	else if (a < b) return -1; //a<b �̸� -1 ��ȯ
	else return 0;	//a=b �̸� 0 ��ȯ
}

//���� Ž�� �Լ� ����
int binarySearch1(int arr[], int searchNum, int left, int right) {

	int middle;

	while (left <= right) {
		//middle����
		middle = (left + right) / 2;

		//�迭 index�� searchNum ���ϱ�
		switch (compare(arr[middle], searchNum)) {

		case -1: left = middle + 1; break;	//middle ���� ã�� ���� ũ��
		case 1: right = middle - 1; break;	//middle ���� ã�� ���� ������
		case 0: return middle;	//middle�� ���� ã�� ���̸� middle ��ȯ

		}
	}
	return -1;	//ã�� ���� ������ -1 ��ȯ
};

//����Լ��� �̿��� ���� Ž�� �Լ� ����
int binarySearch2(int arr[], int searchNum, int left, int right) {

	int middle;

	while (left <= right) {
		//middle����
		middle = (left + right) / 2;

		//�迭 index�� searchNum ���ϱ�
		switch (compare(arr[middle], searchNum)) {
			//middle ���� ã�� ���� ũ�� left = middle+1 ����Լ� ��ȯ
		case -1: return binarySearch2(arr, searchNum, middle + 1, right);
			//middle ���� ã�� ���� ������ right = middle-1 ����Լ� ��ȯ
		case 1: return binarySearch2(arr, searchNum, left, middle - 1);
			//middle�� ���� ã�� ���̸� middle ��ȯ
		case 0: return middle;

		}
	}
	return -1;	//ã�� ���� ������ -1 ��ȯ
};


//���� �Լ�
int main() {
	int n;
	int arr[MAX_SIZE];

	//���� �Լ� ����
	default_random_engine
		engine(static_cast<unsigned int>(time(0)));

	uniform_int_distribution<unsigned int>
		randomInt(1, 100);


	cout << "������ �迭�� ������ �Է��ϼ���: " << endl;
	cin >> n;

	//���� �� �迭�� ����
	for (int i = 0; i < n; i++) {
		arr[i] = randomInt(engine);
	}

	//����
	sort(arr, arr + n);

	//���ĵ� �迭 ���
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	//����Ž��
	int searchNum;
	cout << "=================����Ž��====================\n";
	cout << "ã�� ���� �Է��ϼ���: ";
	cin >> searchNum;
	int index = binarySearch1(arr, searchNum, 0, n - 1);

	if (index == -1) cout << "ã�� ���� �����ϴ�.\n\n";
	else cout << index + 1 << " ��°�� " << searchNum << " ��(��) �����մϴ�.\n\n";

	cout << "=========���ȣ���� �̿��� ����Ž��==========\n";
	cout << "ã�� ���� �Է��ϼ���: ";
	cin >> searchNum;
	index = binarySearch2(arr, searchNum, 0, n - 1);

	if (index == -1) cout << "ã�� ���� �����ϴ�.\n";
	else cout << index + 1 << " ��°�� " << searchNum << " ��(��) �����մϴ�.\n";

}