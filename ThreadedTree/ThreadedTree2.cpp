#include <iostream>
using namespace std;



struct threadedTree {

    int leftThread;
    int rightThread;

    int data;

    threadedTree* leftChild;
    threadedTree* rightChild;

};


threadedTree* findNode(threadedTree* tree){
    threadedTree* temp;
    temp = tree->rightChild;
    if(temp->rightThread!=false){
        while(temp->leftThread!=false) {
            temp = temp->leftChild;
        }
    }
    return temp;
}

void inorderPrint(threadedTree* tree){
    threadedTree* temp = tree;

    while(true){
        cout << "test" << endl;
        findNode(temp);
        if(temp == tree) break;
        cout << temp->data << " ";
    }

}

void insertRight(threadedTree* parent,threadedTree* insert){
    threadedTree* temp;
    insert->rightChild = parent->rightChild;
    insert->rightThread = parent->rightThread;
    insert->leftChild = parent;
    insert->leftThread = true;
    parent->rightChild=insert;
    parent->rightThread = false;

    if(!insert->rightThread){
        temp=findNode(insert);
        temp->leftChild=insert;
    }
}

void insertLeft(threadedTree* parent,threadedTree* insert){
    threadedTree* temp;
    insert->leftChild = parent->leftChild;
    insert->leftThread = parent->leftThread;
    insert->rightChild = parent;
    insert->rightThread = true;
    parent->leftChild = insert;
    parent->rightThread = false;

    if(!insert->leftThread){
        temp=findNode(insert);
        temp->rightChild=insert;
    }

}


void makeRoot(threadedTree* root){
    root->data = 1;
    root->rightChild=root;
    root->leftChild=root;
    root->rightThread=true;
    root->leftThread=true;
}


threadedTree* newNode(threadedTree* tree,int data){
   tree->data=data;
   tree->rightChild = NULL;
   tree->leftChild = NULL;
   tree->rightThread = false;
   tree->leftThread = false;
}


int main() {


    threadedTree* root = new threadedTree();
    makeRoot(root);
    threadedTree* a = new threadedTree();
    newNode(a,1);
    threadedTree* b = new threadedTree();
    newNode(b,2);
    threadedTree* c = new threadedTree();
    newNode(c,3);
    threadedTree* d = new threadedTree();
    newNode(d,4);
    threadedTree* e = new threadedTree();
    newNode(e,5);
    threadedTree* f = new threadedTree();
    newNode(f,6);

    insertLeft(root,a);
    insertRight(root,b);
    insertLeft(a,c);
    insertRight(a,d);
    insertLeft(b,e);
    insertRight(b,f);

    cout<< "inorder: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}