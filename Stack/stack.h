#include<iostream>

using namespace std;
#define MAX_STACK_SIZE 100


class Stack1 {
private:
	int maxStackSize;
	int top;
	int stack[100] = { 0, };

public:
	Stack1(int maxStackSize);
	void isFull();
	void isEmpty();
	void push(int item);
	void pop();
	void showStack();
};