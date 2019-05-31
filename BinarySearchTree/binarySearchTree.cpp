#include <iostream>
#include <string>
using namespace std;

typedef struct element{
    string word;
    string meaning;
};

typedef struct TreeNode{
    element key;
    struct TreeNode *left;
    struct TreeNode *right;
};

//compare function
int compare(element e1, element e2){
    if(e1.word==e2.word) return 0;
    else if(e1.word>e2.word) return 1;
    else return -1;
}

//display function
void display(TreeNode* p){

    if(p != NULL){
        display(p->left);
        cout << p->key.word << " ";
        display(p->right);
    }

}

//search function
TreeNode* search(TreeNode* root,element key){

    TreeNode* p = root;

    //search the position
        while(p != NULL){
        switch(compare(key,p->key)){
            case 1:
                p=p->right;
                break;
            case -1:
                p=p->left;
                break;
            case 0:
                return p;
        }

    }

    return p;
}

//insert function
void insert_node(TreeNode** root,element key){

    TreeNode* p;
    TreeNode* t;
    TreeNode* n;

    t = *root;
    p = NULL;

    while(t!=NULL){
        //if input value is already in the treeNode
        if(compare(key,t->key)==0){
            cout << "Key is already in the tree" << endl;
            return;
        }

        p = t;

        //checking the position
        if(compare(key,t->key)<0){
            t= t->left;
        }
        else{
            t= t->right;
        }

    }
    //initialize new Node and input the value
    n = new TreeNode();

    n->key = key;
    n->left = NULL;
    n->right = NULL;

    //insert new Node
    if(p!=NULL){
        if(compare(key,p->key)<0){
            p->left=n;
        }
        else{
            p->right=n;
        }
    }
    else *root = n;


}

//delete function
void delete_node(TreeNode** root,element key){
    TreeNode* parent_node;
    TreeNode* child_node;
    TreeNode* succ_node;
    TreeNode* succ_parent_node;
    TreeNode* delete_node;

    parent_node = NULL;
    delete_node = *root;

    //checking the position
    while(delete_node!=NULL && compare(key,delete_node->key)!=0){
        parent_node = delete_node;

        //if key is bigger than tree's key
        if(compare(key,delete_node->key)>0){
            delete_node = delete_node->right;
        }
        //if key is smaller the tree's key
        else {
            delete_node = delete_node->left;
        }
    }

    if(delete_node==NULL){
        cout << "Key is not in the tree" << endl;
        return;
    }

    //if delete node is leaf node
    if((delete_node->left==NULL) && (delete_node->right==NULL)){
        //if parent node is not root node
        if(parent_node!=NULL){
            //if parent node's left node is delete node
         if(parent_node->left==delete_node) parent_node->left = NULL;
            //if parent node's right node is delete node
         else parent_node->right = NULL;
        }
        //if parent node is root node
        else *root = NULL;
    }

    //if delete node have one child node
    else if((delete_node->left!=NULL) || (delete_node->right!=NULL)){

        //if delete node's left node is null
        if(delete_node->left==NULL){
            child_node = delete_node->right;
        }
        //if delete node's left node is not null
        else{
            child_node = delete_node->left;
        }

        //if parent node is not root node
        if(parent_node!=NULL){
            //if parent node's left node is delete node
            if(parent_node->left == delete_node){
                parent_node->left = child_node;
            }
            //if parent node's right node is delete node
            else{
                parent_node->right = child_node;
            }
        }
        //if parent node is root node
        else{
            *root = child_node;
        }
    }

    //if delete node have two child node
    else{
        succ_parent_node = delete_node;
        //get delete node's right node
        succ_node = delete_node->right;

        //find the smallest succession node
        while(succ_node->left!=NULL){
            succ_parent_node = succ_node;
            succ_node = succ_node->left;
        }
        //if parent succession node's left node is succession node
        if(succ_parent_node->left == succ_node){
            succ_parent_node->left = succ_node->right;
        }
        //if parent succession node's right node is succession node
        else{
            succ_parent_node->right = succ_node->right;
        }

        //input succession node's key to delete node's key
        delete_node->key = succ_node->key;
        delete_node = succ_node;
    }


    //delete delete_node
    delete(delete_node);



}

//help function
void help(){
    cout << "**********" <<endl;
    cout << "i: insert" << endl;
    cout << "d: delete" << endl;
    cout << "s: search" << endl;
    cout << "p: display" << endl;
    cout << "q: quit" << endl;
    cout << "**********"<< endl;
}


//main
int main() {
    char command;
    element e;
    TreeNode *root = NULL;
    TreeNode *tmp;

    do {
        help();

        cin >> command;

        switch (command) {
            case 'i':
                printf("word:");
                cin >> e.word;
                printf("meaning:");
                cin >> e.meaning;
                insert_node(&root, e);
                break;
            case 'd':
                printf("word:");
                cin >> e.word;
                delete_node(&root, e);
                break;
            case 'p':
                display(root);
                printf("\n");
                break;
            case 's':
                printf("word:");
                cin >> e.word;
                tmp = search(root, e);

                if (tmp != NULL)
                    cout << "meaning:" << tmp->key.meaning;
                    cout << endl;
                break;
        }
    } while (command != 'q');



    return 0;
}