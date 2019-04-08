#include "circularQueue.h"

CircularQueue::CircularQueue(int maxQueueSize)
	:maxQueueSize(maxQueueSize)
{
	front = 0;
	rear = 0;

}

void CircularQueue::isEmpty() {
	if (front == rear) {
		cout << "ť�� ������ϴ�.\n";
	}
}

void CircularQueue::isFull() {
	if (front == (rear+1)%maxQueueSize) {
		cout << "ť�� ��á���ϴ�.\n";
	}
}

void CircularQueue::enQueue(int item) {
	if (front == (rear+1) % maxQueueSize) {
		isFull();
	}
	else {
		rear = ++rear%maxQueueSize;
		queue[rear] = item;
		cout << rear << "��°�� " << item << "�� EnQueue �Ǿ����ϴ�.\n";
	}
}

void CircularQueue::deQueue() {
	if (front == rear) {
		isEmpty();
	}
	
	else {
		
		cout << ++front%maxQueueSize << "��°�� " << queue[front%maxQueueSize] << " �� DeQueue �Ǿ����ϴ�.\n";
		
	}

}

void CircularQueue::showCircularQueue() {
	if (front == rear) {
		isEmpty();
	}
	else {
		cout << "���� ���� ť�� �����ϴ� ����:\n";
		for (int i = 0; i < maxQueueSize; i++) {
			cout << queue[i] << " ";
		}
		cout << "\n";
	}


}