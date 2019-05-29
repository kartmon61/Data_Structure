#include <iostream>
using namespace std;

struct threadedTree {

    int leftThread;
    int rightThread;

    int data;

    threadedTree* leftChild;
    threadedTree* rightChild;

};

//making new node function
struct threadedTree* new_node(int data){
    struct threadedTree* node_ptr;
    node_ptr = new threadedTree();
    node_ptr->data = data;
    node_ptr->leftChild=NULL;
    node_ptr->rightChild=NULL;
    node_ptr->leftThread=false;
    node_ptr->rightThread=false;

    return node_ptr;
}

threadedTree* createThread(threadedTree* root){
    if (root == NULL) return NULL;

    if(root->leftChild == NULL && root->rightChild == NULL)
        return root;

    if(root->leftChild!=NULL){
        threadedTree* tr = createThread(root->leftChild);

        tr->leftChild = root;
        tr->leftThread = true;

    }

    if(root->rightChild!=NULL) return root;

}


threadedTree* findThread(threadedTree* tree){
    threadedTree* temp;
    temp = tree->rightChild;
    if(!tree->rightThread){
        while(!temp->leftThread) {
            temp = temp->leftChild;
        }
    }
    return temp;
}

void inorder(threadedTree* tree){
    threadedTree* temp = tree;

    while(true){
        temp = findThread(temp);
        if(temp == tree){
            break;
        }

        cout << temp->data;
        temp = temp->
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
        temp=findThread(insert);
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
        temp=findThread(insert);
        temp->rightChild=insert;
    }

}


int main() {

    cout << "hello" << endl;

    struct threadedTree* root;
    root = new_node(1);
    root->rightChild = new_node(2);
    root->rightChild->leftChild = root;
    root->rightChild->leftThread = true;
    root->leftChild = new_node(3);
    root->leftChild->rightChild = new_node(4);
    root->leftChild->rightChild->rightChild = root->leftChild;
    root->leftChild->rightChild->rightThread = true;
    root->leftChild->rightChild->leftChild = root;
    root->leftChild->rightChild->leftThread = true;

    cout<< "inorder: ";
    inorder(root);
    cout << endl;
    cout << "hello1" << endl;





    return 0;
}