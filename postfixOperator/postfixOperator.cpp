#include<iostream>
#include<string>
using namespace std;

#define MAX 100
string postfix;

int stack[MAX];
int top = -1;
//스택 push
void push(int item) {
	if (top > MAX-1) {
		cout << "스택이 꽉찼습니다. \n";
		exit(1);
	}
	else stack[++top] = item;
}
//스택 pop
int pop() {
	if (top == -1) {
		cout << "스택이 비었습니다.\n";
		exit(1);
	}
	else return stack[top--];
}
//enum구현
enum Precedence
{PLUS, MINUS, TIMES, DIVIDE, MOD, OPERAND};

//token으로 쪼개기
Precedence getToken(char& symbol, int& i) {
	symbol = postfix[i++];
	
	//cout << i << endl;
	switch (symbol) {
		case '+': return PLUS;
		case '-': return MINUS;
		case '*': return TIMES;
		case '/': return DIVIDE;
		case '%': return MOD;
		default: return OPERAND;
	}
}
//한개의 연산자와 두개의 피연산자를 받아서 계산
int operation(Precedence token, int op1, int op2) {
	switch (token) {
		case PLUS: return op1+op2;
		case MINUS: return op1-op2;
		case TIMES: return op1*op2;
		case DIVIDE: return op1/op2;
		case MOD: return op1%op2;
		default: return -1;
	}
}

int main() {
	
	cout << "식을 입력하세요:\n";
	cin >> postfix;
	int i = 0;
	char symbol;
	Precedence token = getToken(symbol, i);
	
	//postfix의 길이까지 동작
	while (i<=postfix.length()) {
		//token이 피연산자이면 push
		if (token == OPERAND) {
			push(symbol - '0');
		}
		//token이 연산자이면 스택에서 피연산자 두개를 pop하여 연산
		else {
			int op2 = pop();
			int op1 = pop();
			//연산 후 결과 push
			push(operation(token, op1, op2));
		}
		//다음 token 만들기
		token = getToken(symbol, i);
	}
	//결과 출력
	cout << "결과:" <<pop() << "\n";
}
