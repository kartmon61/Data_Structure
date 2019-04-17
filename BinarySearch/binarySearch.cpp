#include<iostream>
#include<random>
#include<ctime>
#include<algorithm>

#define MAX_SIZE 101
using namespace std;

//비교 함수 생성
int compare(int a, int b) {
	if (a > b) return 1; //a>b 이면 1 반환
	else if (a < b) return -1; //a<b 이면 -1 반환
	else return 0;	//a=b 이면 0 반환
}

//이진 탐색 함수 생성
int binarySearch1(int arr[], int searchNum, int left, int right) {

	int middle;

	while (left <= right) {
		//middle정의
		middle = (left + right) / 2;

		//배열 index와 searchNum 비교하기
		switch (compare(arr[middle], searchNum)) {

		case -1: left = middle + 1; break;	//middle 보다 찾는 수가 크면
		case 1: right = middle - 1; break;	//middle 보다 찾는 수가 작으면
		case 0: return middle;	//middle의 값이 찾는 수이면 middle 반환

		}
	}
	return -1;	//찾는 값이 없으면 -1 반환
};

//재귀함수를 이용한 이진 탐색 함수 생성
int binarySearch2(int arr[], int searchNum, int left, int right) {

	int middle;

	while (left <= right) {
		//middle정의
		middle = (left + right) / 2;

		//배열 index와 searchNum 비교하기
		switch (compare(arr[middle], searchNum)) {
			//middle 보다 찾는 수가 크면 left = middle+1 재귀함수 반환
		case -1: return binarySearch2(arr, searchNum, middle + 1, right);
			//middle 보다 찾는 수가 작으면 right = middle-1 재귀함수 반환
		case 1: return binarySearch2(arr, searchNum, left, middle - 1);
			//middle의 값이 찾는 수이면 middle 반환
		case 0: return middle;

		}
	}
	return -1;	//찾는 값이 없으면 -1 반환
};


//메인 함수
int main() {
	int n;
	int arr[MAX_SIZE];

	//랜덤 함수 생성
	default_random_engine
		engine(static_cast<unsigned int>(time(0)));

	uniform_int_distribution<unsigned int>
		randomInt(1, 100);


	cout << "저장할 배열의 갯수를 입력하세요: " << endl;
	cin >> n;

	//랜덤 수 배열에 저장
	for (int i = 0; i < n; i++) {
		arr[i] = randomInt(engine);
	}

	//정렬
	sort(arr, arr + n);

	//정렬된 배열 출력
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	//이진탐색
	int searchNum;
	cout << "=================이진탐색====================\n";
	cout << "찾을 수를 입력하세요: ";
	cin >> searchNum;
	int index = binarySearch1(arr, searchNum, 0, n - 1);

	if (index == -1) cout << "찾는 수가 없습니다.\n\n";
	else cout << index + 1 << " 번째에 " << searchNum << " 이(가) 존재합니다.\n\n";

	cout << "=========재귀호출을 이용한 이진탐색==========\n";
	cout << "찾을 수를 입력하세요: ";
	cin >> searchNum;
	index = binarySearch2(arr, searchNum, 0, n - 1);

	if (index == -1) cout << "찾는 수가 없습니다.\n";
	else cout << index + 1 << " 번째에 " << searchNum << " 이(가) 존재합니다.\n";

}