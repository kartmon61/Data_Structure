//
//  main.cpp
//  multipleStack
//
//  Created by 이진호 on 29/04/2019.
//  Copyright © 2019 이진호. All rights reserved.
//

#include "multipleStack.h"

int main() {
    int n;
    cout << "만들고 싶은 스택의 수 입력:\n";
    cin >> n;
    MultipleStack ms(n);

    int a;
    int item;
    int choice;
    
    cout << "\n원하는 작업을 선택하세요:\n"
    "(1)pop (2)push (3)ShowStack (4)종료:\n";
    cin >> choice;
    
    while (choice != 4) {
        
        switch (choice) {
            case 1:
                cout << "몇번째 스택?";
                cin >> a;
                ms.pop(a); break;
                
            case 2:
                cout << "몇번째 스택?";
                cin >> a;
                cout << "\n삽입할 수를 입력하세요:\n";
                cin >> item;
                ms.push(a,item); break;
                
            case 3:
                cout << "몇번째 스택?";
                cin >> a;
                ms.showMultipleStack(a); break;
        }
        
        cout << "\n원하는 작업을 선택하세요:\n"
        "(1)pop (2)push (3)ShowStack (4)종료:\n";
        
        cin >> choice;
    }
    
}
