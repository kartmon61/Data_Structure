
//������� ����
#include<iostream>
#include<string>

using namespace std;


//�ϳ��� �Լ� ����
void hanoi(int T, string source, string temporal, string target)
{
	//T=1 �϶� ��� ��, �Լ� ����
	if (T == 1)
	{
		cout << "Move disk" << T << " from tower " << source << " to tower " << target << "\n";
	}

	else
	{
		//��� ȣ�� hanoi(T-1)
		hanoi(T - 1, source, target, temporal);
		cout << "Move disk" << T << " from tower " << source << " to tower " << target << "\n";
		//��� ȣ�� hanoi(T-1)
		hanoi(T - 1, temporal, source, target);

	}

}
//���� �Լ�
int main()
{
	int T;

	cin >> T;

	cout << "Input n : " << T << "\n\n";

	//�ϳ��� �Լ� ȣ�� ( 
	hanoi(T, "A", "B", "C");

	system("pause");

}