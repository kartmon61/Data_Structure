
#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

class Stack{

private:
    node* header;

public:
    Stack(){
        header = new node();
    }

    //push function
    void push(int item){
        node* h = header;
        node* p;
        // h->next node until next node is null
        while(h->next != NULL){
            h=h->next;
        }
        //make new node
        p = new node();
        //save item to new node
        p->data=item;
        //new node -> next is null
        p->next = NULL;
        //h-> next node is new node
        h->next=p;

    }

    int pop(){
        node* h = header;
        node* n = h->next;
        // n->next node until next node is null
        while(n->next != NULL){
            h=h->next;
            n=h->next;
        }
        //save pop item
        int item = n->data;
        //h-> next node is null
        h->next =NULL;
        //delete n node
        delete(n);
        //return pop item
        return item;

    }

    void print_stack(){
        node* h=header;
        h->next;
        //print until h->next node->next node is null
        while(h->next !=NULL){
            cout << h->data << " ";
            h=h->next;
        }
        //print h->next node is null
        cout << h->data;
        cout << endl;

    }

    void clear_stack(){
        node* h = header;
        //pop until next node is null
        while(h->next !=NULL){
            pop();
        }
    }



};



int main() {

    Stack stack;

    cout << "1 push" << endl;
    stack.push(1);
    cout << "2 push" << endl;
    stack.push(2);
    cout << "3 push" << endl;
    stack.push(3);
    cout << "stack " << endl;
    stack.print_stack();
    cout <<  "pop data : "<< stack.pop() << endl;
    cout << "stack " << endl;
    stack.print_stack();
    cout << "스택 삭제" << endl;
    stack.clear_stack();
    cout << "stack ";
    stack.print_stack();



    return 0;
}