#include "stack.h"

Stack1::Stack1(int maxStackSize)
	:maxStackSize(maxStackSize)
{
	top = -1;
}

void Stack1::isEmpty() {
	if (top == -1) {
		cout << "스택이 비었습니다.\n";
	}

}

void Stack1::isFull() {
	if (top >= maxStackSize - 1) {
		cout << "스택이 꽉 찼습니다.\n";
	}
}

void Stack1::push(int item) {
	if (top >= maxStackSize - 1) {
		isFull();
	}
	else {
		stack[++top] = item;
		cout << top << "번째에 " << item << "이 push 되었습니다.\n";
	}
}

void Stack1::pop() {
	if (top == -1) {
		isEmpty();
	}
	else {
		
		cout << top << "번째에 " << stack[top] << "이 pop 되었습니다.\n";
		top--;
	}
}

void Stack1::showStack() {
	if (top == -1) {
		isEmpty();
	}
	else {
		cout << "현재 스택에 존재하는 수는:\n";
		for (int i = 0; i < maxStackSize; i++) {
			cout << stack[i] << " ";
		}
		cout << "\n";
	}
}