#include "circularQueue.h"

CircularQueue::CircularQueue(int maxQueueSize)
	:maxQueueSize(maxQueueSize)
{
	front = 0;
	rear = 0;

}

void CircularQueue::isEmpty() {
	if (front == rear) {
		cout << "큐가 비었습니다.\n";
	}
}

void CircularQueue::isFull() {
	if (front == (rear+1)%maxQueueSize) {
		cout << "큐가 꽉찼습니다.\n";
	}
}

void CircularQueue::enQueue(int item) {
	if (front == (rear+1) % maxQueueSize) {
		isFull();
	}
	else {
		rear = ++rear%maxQueueSize;
		queue[rear] = item;
		cout << rear << "번째에 " << item << "이 EnQueue 되었습니다.\n";
	}
}

void CircularQueue::deQueue() {
	if (front == rear) {
		isEmpty();
	}
	
	else {
		
		cout << ++front%maxQueueSize << "번째에 " << queue[front%maxQueueSize] << " 이 DeQueue 되었습니다.\n";
		
	}

}

void CircularQueue::showCircularQueue() {
	if (front == rear) {
		isEmpty();
	}
	else {
		cout << "현재 원형 큐에 존재하는 수는:\n";
		for (int i = 0; i < maxQueueSize; i++) {
			cout << queue[i] << " ";
		}
		cout << "\n";
	}


}