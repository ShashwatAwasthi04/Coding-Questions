#include<iostream>
#include<iomanip>
using namespace std;

struct binaryTree{
    int val;
    struct binaryTree* l;  //left branch
    struct binaryTree* r;  //right branch
};

struct binaryTree* createtree(int value){
    struct binaryTree* n= new struct binaryTree[1];
    n->l=NULL;
    n->r=NULL;
    n->val= value;
    return n;
}

int height(struct binaryTree* p){   // takes a pointer

    if(p==NULL){return 0;}

    int x = height(p->l);
    int y = height(p->r);

    return (x>y)? x+1 : y+1 ;      // takes the branch having maximum nodes

}

int node(struct binaryTree* p){

    if(p==NULL){
        return 0;
    }

    int x = node(p->l);
    int y = node(p->r);

    return x+y+1;           // nodes in left + nodes in right + itself
}

int sum(struct binaryTree* p){
    if(p== NULL){
        return 0;
    }

    int x = sum(p->l);
    int y = sum(p->r);

    return x + y + p->val;      // value of left + value of right + value of itself
}

int main(){
    
    //EXAMPLE
    //constructing a binaryTree structure using createtree function

    struct binaryTree* p = createtree(4);
    struct binaryTree* p1 = createtree(2);
    struct binaryTree* p2 = createtree(8);
    struct binaryTree* p3 = createtree(5);
    struct binaryTree* p4 = createtree(6);   //creating the branches of binary tree
    struct binaryTree* p5 = createtree(12);   
    struct binaryTree* p6 = createtree(15);   
    struct binaryTree* p7 = createtree(34);  
    struct binaryTree* p8 = createtree(23);   

// BINARY TREE LOOKS LIKE: 

//             4
//            / \
//           2   8
//          / \  /
//         5  6 12
//              / \
//             15  34
//              \
//               23
              
    p->l = p1;   //linking the branches of binary tree
    p->r = p2;
    p1->l = p3;
    p1->r = p4;
    p2->l = p5;
    p5->l = p6;
    p5->r = p7;
    p6->r = p8;

    cout<<"Height: ";
    cout<<height(p)<<endl;

    cout<<"Number of nodes: ";
    cout<<node(p)<<endl;

    cout<<"Sum of node values: ";
    cout<<sum(p)<<endl;
 
    return 0;
}