#include <iostream>

using namespace std;

//define node
struct node{
    int data;
    struct node* r_child;
    struct node* l_child;
};

//making new node function
struct node* new_node(int data){
    struct node* node_ptr;
    node_ptr = new node();
    node_ptr->data = data;
    node_ptr->l_child=NULL;
    node_ptr->r_child=NULL;

    return node_ptr;
}
//preorder function
void preorder(struct node* root){
    if(root){
        cout<< root->data << " ";
        preorder(root->l_child);
        preorder(root->r_child);
    }
}
//inorder function
void inorder(struct node* root){
    if(root){
        inorder(root->l_child);
        cout<< root->data << " ";
        inorder(root->r_child);
    }
}

//postorder function
void postorder(struct node* root){
    if(root){
        postorder(root->l_child);
        postorder(root->r_child);
        cout<< root->data << " ";
    }
}

//checking leaf function
bool is_Leaf(struct node* n){
    if(n->l_child==NULL && n->r_child==NULL) return true;
    else return false;
}
//get Max function
int get_Max(int a,int b){
    return a>b?a:b;
}
//get Depth function
int get_Depth(struct node* n){
    if(is_Leaf(n) || n==NULL) return 0;
    else{
        //when calling get_Max + 1 , compare l_child and r_child Depth
        return get_Max(get_Depth(n->l_child),get_Depth(n->l_child))+1;
    }
}


int main(){
    struct node* root;
    root = new_node(4);
    root->r_child = new_node(5);
    root->r_child->r_child = new_node(6);
    root->l_child = new_node(2);
    root->l_child->l_child = new_node(1);
    root->l_child->r_child = new_node(3);



    cout << "preorder: ";
    preorder(root);
    cout << endl;
    cout << "inorder: ";
    inorder(root);
    cout << endl;
    cout << "postorder: ";
    postorder(root);
    cout << endl;

    cout << "Depth : "<< get_Depth(root) << endl;
    cout << "Level : "<< get_Depth(root)+1;

}
