
//
//  InfixToPostfix.cpp
//  data_structure
//
//  Created by 이진호 on 27/04/2019.
//  Copyright © 2019 이진호. All rights reserved.
//

#include <iostream>
#include <string>


using namespace std;

#define MAX_SIZE 100
char stack[MAX_SIZE];
int top =-1;

//스택이 꽉찼을 때
bool _isFull(){
    if(top==MAX_SIZE) return true;
    else return false;
}

//스택이 비었을 때
bool _isEmpty(){
    if(top == -1) return true;
    else return false;
}
//push 함수
void _push(char item){
    //스택이 꽉찼을때
    if(_isFull()){
        cout << "Stack is Full" << endl;
        return;
    }
    //스택이 꽉차지않았을때
    stack[++top]=item;
}
//pop 함수
char _pop(){
    //스택이 비었을때
    if(_isEmpty()){
        cout << "Stack is Empty" << endl;
        return -1;
    }
    //스택이 비지않았을때
    return stack[top--];
}


//우선순위 연산자 계산
int _compare(char item){
    
    if(item == '+' || item == '-') return 1;
    
    else if (item == '*' || item == '/') return 2;
    
    else  return -1;
    
}

//infix를 postfix로 바꾸는 함수
void infixToPostfix(string infix){
    string result;
    int lparen=0;
    int rparen=0;
    //infix의 길이 만큼 동작
    for(int i=0;i<infix.length();i++){
        //infix의 처음에 -가 있을때,
        if(infix[0] == '-' && i==0){
            result+='-';
            continue;
        }
        //infix의 처음에 +가 있을때,
        else if(infix[0] == '+' && i==0){
            continue;
        }
        //infix에 숫자가 있을때,
        else if(infix[i] >= '0' && infix[i] <='9'){
            
            result +=infix[i];
        }
        //infix의 i번째에 (가 있을때,
        else if(infix[i]=='('){
            lparen++;
            _push(infix[i]);
            //양수 음수 표현
            if(infix[i+1] == '-'){
                i++;
                result+=infix[i];
            }
            else if(infix[i+1] == '+'){
                i++;
            }
        }
        //infix의 i번째에 )가 있을때,
        else if (infix[i] == ')'){
            rparen++;
            //스택에 ( 를 찾을때 까지 pop하여 result에 추가
            while(stack[top] != '(' && top !=-1){
                
                char oper = stack[top];
                _pop();
                result =result + " "+ oper;
            }
            // ( 연산자를 pop
            if(stack[top]=='('){
                _pop();
            }
        }
        //infix에 연산자가 있을때, 연산자 비교
        else if(infix[i] == '*' || infix[i] == '/' || infix[i] == '+'
                || infix[i] == '-'){
            //스택에 있는 연산자와 infix의 i번째 연산자의 우선순위 비교
            while(top!=-1 && _compare(infix[i]) <= _compare(stack[top])){
                //스택에 있는 연산자 pop
                result=result+" "+_pop();
            }
            
            result+=" ";
            //infix 연산자 push
            _push(infix[i]);
            
            //양수 음수 표현
            if(infix[i+1] == '-'){
                i++;
                result+=infix[i];
            }
            else if(infix[i+1] == '+'){
                i++;
            }
        }
        //에외 처리
        else{
            
            cout << infix[i]<<" 는 적절하지 않은 피연산자입니다.\n";
            exit(1);
            
        }
    }
    //괄호의 갯수가 맞지 않을때,
    if(lparen!=rparen){
        cout << "올바르지 않은 괄호 연산자 사용입니다.\n";
        exit(1);
    }
    //스택에 들어있던 연산자 모두 pop하여 출력
    while(top!=-1){
        
        result=result+" "+_pop();
    }
    
    
    cout << result << endl;
    
    
}

//메인함수
int main() {
    
    string infix;
    
    cout << "input infix\n";
    getline(cin,infix,'\n');
    //피연산자가 입력되지 않을때까지 반복
    while(infix!=""){
        infixToPostfix(infix);
        cout << endl;
        cout << "input infix\n";
        getline(cin,infix,'\n');
    }
    
    return 0;
}


