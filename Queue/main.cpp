#include "queue.h"

int main() {
	int maxQueueSize;
	cout << "ť�� ũ�⸦ �Է��ϼ���:\n";
	cin >> maxQueueSize;

	Queue1 q(maxQueueSize);

	int choice = 0;
	int item = 0;
	cout << "���ϴ� �۾��� �����ϼ���\n"
		"(1)pop (2)push (3)ShowStack (4)����:\n";
	cin >> choice;
	while (choice != 4) {

		switch (choice) {
		case 1: q.pop(); break;

		case 2:
			cout << "\n������ ���� �Է��ϼ���:\n";
			cin >> item;
			q.push(item); break;

		case 3:
			q.showQueue(); break;
		}

		cout << "\n���ϴ� �۾��� �����ϼ���\n"
			"(1)pop (2)push (3)ShowStack (4)����:\n";

		cin >> choice;
	}


}
 