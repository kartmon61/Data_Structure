#include "circularQueue.h"

int main() {
	int maxQueueSize = 0;
	cout << "회전 큐의 크기를 입력하세요:\n";
	cin >> maxQueueSize;

	CircularQueue cq(maxQueueSize);

	int choice = 0;
	int item = 0;
	cout << "\n원하는 작업을 선택하세요\n"
		"(1)dequeue (2)enqueue (3)ShowQueue (4)종료:\n";
	cin >> choice;
	while (choice != 4) {

		switch (choice) {
		case 1: cq.deQueue(); break;

		case 2:
			cout << "\n삽입할 수를 입력하세요:\n";
			cin >> item;
			cq.enQueue(item); break;

		case 3:
			cq.showCircularQueue(); break;
		}

		cout << "\n원하는 작업을 선택하세요\n"
			"(1)dequeue (2)enqueue (3)ShowQueue (4)종료:\n\n";

		cin >> choice;
	}


}