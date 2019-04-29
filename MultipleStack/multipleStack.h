//
//  multipleStack.h
//  multipleStack
//
//  Created by 이진호 on 29/04/2019.
//  Copyright © 2019 이진호. All rights reserved.
//

#ifndef multipleStack_h
#define multipleStack_h

#include<iostream>

#define MEMORY_SIZE 100    //최대 메모리 크기
#define MAX_STACKS 10    //최대 만들수 있는 스택의 개수

using namespace std;

class MultipleStack {
private:
    int memory[MEMORY_SIZE];
    int n;
    
public:
    int top[MAX_STACKS];    //스택의 최상단 원소의 위치
    int boundary[MAX_STACKS];   //스택의 최하단 원소의 위치
    
    MultipleStack(int n);
    bool stackEmpty(int a);
    bool stackFull(int a);
    void push(int a, int item);
    void pop(int a);
    void showMultipleStack(int a);
    
};


#endif /* multipleStack_h */

