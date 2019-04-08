#include "queue.h"

Queue1::Queue1(int maxSize)
	:maxQueueSize(maxSize)
{
	this->front = -1;
	this->rear = -1;
}

void Queue1::isEmpty() {
	if (rear == front) {
		cout << "큐가 비었습니다.\n";
	}
}

void Queue1::isFull() {
	if (rear == maxQueueSize-1) {
		cout << "큐가 꽉찼습니다.\n";
	}
}


void Queue1::push(int item) {
	if (rear >= maxQueueSize-1) {
		isFull();
	}
	else {
		queue[++rear] = item;
		cout << rear << "번째에 " << item << "이 push 되었습니다.\n";
	}
	
}

void Queue1::pop() {
	if (rear == front) {
		isEmpty();
	}
	else {
		++front;
		cout << front << "번째에 " << queue[front] << "이 pop 되었습니다.\n";
	}
	

}

void Queue1::showQueue() {
	if (front == rear) {
		isEmpty();
	}
	else {
		cout << "현재 큐에 존재하는 수는:\n";
		for (int i = 0; i < maxQueueSize; i++) {
			cout << queue[i] << " ";
		}
		cout << "\n";
	}
	
}