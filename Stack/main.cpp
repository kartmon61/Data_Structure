#include "stack.h"

int main() {
	int maxStackSize = 0;
	cout << "스택의 크기를 입력하세요:\n";
	cin >> maxStackSize;

	Stack1 s(maxStackSize);

	int choice = 0;
	int item = 0;
	cout << "\n원하는 작업을 선택하세요\n"
		"(1)pop (2)push (3)ShowStack (4)종료:\n";
	cin >> choice;
	while (choice != 4) {

		switch (choice) {
		case 1: s.pop(); break;

		case 2: 
			cout << "\n삽입할 수를 입력하세요:\n";
			cin >> item;
			s.push(item); break;

		case 3:
			s.showStack(); break;
		}

		cout << "\n원하는 작업을 선택하세요\n"
			"(1)pop (2)push (3)ShowStack (4)종료:\n\n";

		cin >> choice;
	}


}