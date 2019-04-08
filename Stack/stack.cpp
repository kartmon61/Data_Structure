#include "stack.h"

Stack1::Stack1(int maxStackSize)
	:maxStackSize(maxStackSize)
{
	top = -1;
}

void Stack1::isEmpty() {
	if (top == -1) {
		cout << "������ ������ϴ�.\n";
	}

}

void Stack1::isFull() {
	if (top >= maxStackSize - 1) {
		cout << "������ �� á���ϴ�.\n";
	}
}

void Stack1::push(int item) {
	if (top >= maxStackSize - 1) {
		isFull();
	}
	else {
		stack[++top] = item;
		cout << top << "��°�� " << item << "�� push �Ǿ����ϴ�.\n";
	}
}

void Stack1::pop() {
	if (top == -1) {
		isEmpty();
	}
	else {
		
		cout << top << "��°�� " << stack[top] << "�� pop �Ǿ����ϴ�.\n";
		top--;
	}
}

void Stack1::showStack() {
	if (top == -1) {
		isEmpty();
	}
	else {
		cout << "���� ���ÿ� �����ϴ� ����:\n";
		for (int i = 0; i < maxStackSize; i++) {
			cout << stack[i] << " ";
		}
		cout << "\n";
	}
}