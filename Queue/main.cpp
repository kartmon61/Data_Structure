#include "queue.h"

int main() {
	int maxQueueSize;
	cout << "큐의 크기를 입력하세요:\n";
	cin >> maxQueueSize;

	Queue1 q(maxQueueSize);

	int choice = 0;
	int item = 0;
	cout << "원하는 작업을 선택하세요\n"
		"(1)pop (2)push (3)ShowStack (4)종료:\n";
	cin >> choice;
	while (choice != 4) {

		switch (choice) {
		case 1: q.pop(); break;

		case 2:
			cout << "\n삽입할 수를 입력하세요:\n";
			cin >> item;
			q.push(item); break;

		case 3:
			q.showQueue(); break;
		}

		cout << "\n원하는 작업을 선택하세요\n"
			"(1)pop (2)push (3)ShowStack (4)종료:\n";

		cin >> choice;
	}


}
 