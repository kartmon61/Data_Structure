#include<iostream>

using namespace std;

class CircularQueue{

private:
	int queue[100] = {0,};
	int front;
	int rear;
	int maxQueueSize;

public:
	CircularQueue(int);
	void isEmpty();
	void isFull();
	void enQueue(int item);
	void deQueue();
	void showCircularQueue();

};