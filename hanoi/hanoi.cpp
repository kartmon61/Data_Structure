
//헤더파일 선언
#include<iostream>
#include<string>

using namespace std;


//하노이 함수 정의
void hanoi(int T, string source, string temporal, string target)
{
	//T=1 일때 출력 후, 함수 종료
	if (T == 1)
	{
		cout << "Move disk" << T << " from tower " << source << " to tower " << target << "\n";
	}

	else
	{
		//재귀 호출 hanoi(T-1)
		hanoi(T - 1, source, target, temporal);
		cout << "Move disk" << T << " from tower " << source << " to tower " << target << "\n";
		//재귀 호출 hanoi(T-1)
		hanoi(T - 1, temporal, source, target);

	}

}
//메인 함수
int main()
{
	int T;

	cin >> T;

	cout << "Input n : " << T << "\n\n";

	//하노이 함수 호출 ( 
	hanoi(T, "A", "B", "C");

	system("pause");

}