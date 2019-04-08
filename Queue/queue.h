#include <iostream>

using namespace std;

class Queue1 {
private:
	int maxQueueSize;
	int queue[100] = {};
	int front;
	int rear;

public:
	Queue1(int);
	void isEmpty();
	void isFull();
	void push(int item);
	void pop();
	void showQueue();

};