//
//  multipleStack.cpp
//  multipleStack
//
//  Created by 이진호 on 29/04/2019.
//  Copyright © 2019 이진호. All rights reserved.
//

#include "multipleStack.h"
//constructor
MultipleStack::MultipleStack(int n) {
    this->n = n;
    
    //첫번째 스택 생성
    top[0] = -1; //스택의 최상단 원소의 위치
    boundary[0] = -1;    //스택의 최하단 원소의 위치
    
    //n-1개의 스택 생성
    for (int i = 1; i < n; i++) {
        top[i] = boundary[i] = MEMORY_SIZE / n * i;
    }
    //n+1번째 boundary는 메모리의 마지막 위치를 가리킨다.
    boundary[n] = MEMORY_SIZE - 1;
    
}
//isEmpty
bool MultipleStack::stackEmpty(int a) {
    if (top[a-1]==boundary[a-1]) return true;
    else return false;
}
//isfull
bool MultipleStack::stackFull(int a) {
    if (top[a-1] == boundary[a]) return true;
    else return false;
}
//push
void MultipleStack::push(int a, int item) {
    if (stackFull(a))
        cout << a << "번째 스택이 꽉찼습니다.\n";
    
    else {
        memory[++top[a-1]]=item;
        cout << a << "번째의 스택: " << top[a-1]-boundary[a-1] << "번째에 "
        << item << "이 push\n";
        
    }
}
//pop
void MultipleStack::pop(int a) {
    if (stackEmpty(a)) cout << a << "번째 스택: 비었습니다.\n";
    else {
        cout << a << "번째 스택: " << top[a-1]-boundary[a-1] << "번째에 "
        << memory[top[a-1]--] << "이 pop\n";
    }
}
//showStack
void MultipleStack::showMultipleStack(int a) {
    if (stackEmpty(a)) cout << a << "번째 스택: 비었습니다.\n";
    
    else if(a > this->n && a<1){
        cout<< "스택의 범위를 초과 했습니다.\n";
    }
    else {
        cout << "현재 스택에 존재하는 수는:\n";
        for (int i = 1; i <= memory[top[a-1]]; i++) {
            cout << memory[boundary[a-1]+i] << " ";
        }
        cout << "\n";
    }
    
    
}
