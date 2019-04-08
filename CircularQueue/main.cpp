#include "circularQueue.h"

int main() {
	int maxQueueSize = 0;
	cout << "ȸ�� ť�� ũ�⸦ �Է��ϼ���:\n";
	cin >> maxQueueSize;

	CircularQueue cq(maxQueueSize);

	int choice = 0;
	int item = 0;
	cout << "\n���ϴ� �۾��� �����ϼ���\n"
		"(1)dequeue (2)enqueue (3)ShowQueue (4)����:\n";
	cin >> choice;
	while (choice != 4) {

		switch (choice) {
		case 1: cq.deQueue(); break;

		case 2:
			cout << "\n������ ���� �Է��ϼ���:\n";
			cin >> item;
			cq.enQueue(item); break;

		case 3:
			cq.showCircularQueue(); break;
		}

		cout << "\n���ϴ� �۾��� �����ϼ���\n"
			"(1)dequeue (2)enqueue (3)ShowQueue (4)����:\n\n";

		cin >> choice;
	}


}