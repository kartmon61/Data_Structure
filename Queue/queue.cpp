#include "queue.h"

Queue1::Queue1(int maxSize)
	:maxQueueSize(maxSize)
{
	this->front = -1;
	this->rear = -1;
}

void Queue1::isEmpty() {
	if (rear == front) {
		cout << "ť�� ������ϴ�.\n";
	}
}

void Queue1::isFull() {
	if (rear == maxQueueSize-1) {
		cout << "ť�� ��á���ϴ�.\n";
	}
}


void Queue1::push(int item) {
	if (rear >= maxQueueSize-1) {
		isFull();
	}
	else {
		queue[++rear] = item;
		cout << rear << "��°�� " << item << "�� push �Ǿ����ϴ�.\n";
	}
	
}

void Queue1::pop() {
	if (rear == front) {
		isEmpty();
	}
	else {
		++front;
		cout << front << "��°�� " << queue[front] << "�� pop �Ǿ����ϴ�.\n";
	}
	

}

void Queue1::showQueue() {
	if (front == rear) {
		isEmpty();
	}
	else {
		cout << "���� ť�� �����ϴ� ����:\n";
		for (int i = 0; i < maxQueueSize; i++) {
			cout << queue[i] << " ";
		}
		cout << "\n";
	}
	
}