#include "stack.h"

int main() {
	int maxStackSize = 0;
	cout << "������ ũ�⸦ �Է��ϼ���:\n";
	cin >> maxStackSize;

	Stack1 s(maxStackSize);

	int choice = 0;
	int item = 0;
	cout << "\n���ϴ� �۾��� �����ϼ���\n"
		"(1)pop (2)push (3)ShowStack (4)����:\n";
	cin >> choice;
	while (choice != 4) {

		switch (choice) {
		case 1: s.pop(); break;

		case 2: 
			cout << "\n������ ���� �Է��ϼ���:\n";
			cin >> item;
			s.push(item); break;

		case 3:
			s.showStack(); break;
		}

		cout << "\n���ϴ� �۾��� �����ϼ���\n"
			"(1)pop (2)push (3)ShowStack (4)����:\n\n";

		cin >> choice;
	}


}