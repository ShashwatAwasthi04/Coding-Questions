#include <iostream>
#include <iomanip>
using namespace std;

struct binaryTree
{
    int val;
    struct binaryTree *l; //left branch
    struct binaryTree *r; //right branch
    int height;         // keeps track of the height
}*root = NULL;

// to keep track of modified root elements

struct binaryTree *createtree(int value)
{
    struct binaryTree *n = new struct binaryTree[1];
    n->l = NULL;
    n->r = NULL;
    n->val = value;
    n->height = 1;
    return n;
}   // while creating, it is a leaf

int BalanceFactor(struct binaryTree* p){
    if(p==NULL){return 0;}
    int left = (p->l != NULL) ? p->l->height: 0;        // left child height
    int right = (p->r != NULL) ? p->r->height: 0;      // right child height

    return left-right;
}

int nodeheight(struct binaryTree* p){     // returns height of a node
    int left = (p->l !=NULL) ? p->l->height: 0;        // left child height
    int right = (p->r !=NULL) ? p->r->height: 0;      // right child height

    if(left>right){
        return left+1;
    }
    else{
        return right +1;
    }
}

struct binaryTree* LLrotation(struct binaryTree* p){
    struct binaryTree* pl = p->l;
    struct binaryTree* plr = pl->r;

    pl->r = p;
    p->l = plr;

    p->height = nodeheight(p);
    pl->height = nodeheight(pl);

    if(root==p){       // if p was the root, then root will change
        root = pl;
    }

    return pl;
}

struct binaryTree* LRrotation(struct binaryTree* p){
    struct binaryTree* pl = p->l;
    struct binaryTree* plr = pl->r;

    pl->r = plr->l;
    p->l = plr->r;

    plr->l = pl;
    plr->r = p;

    p->height = nodeheight(p);
    pl->height=  nodeheight(pl);
    plr->height = nodeheight(plr);

    if(root == p){      // if p was the root, then root will change
        root = plr;
    }

    return plr;

}

struct binaryTree* RRrotation(struct binaryTree* p){
    return NULL;
}

struct binaryTree* RLrotation(struct binaryTree* p){
    return NULL;
}

// recusively creating binary tree
struct binaryTree* Rinsert(struct binaryTree* p, int key){
    
    if(p == NULL){
        return(createtree(key));
    }

    else if(key<p->val){
        p->l = Rinsert(p->l, key);
    }
    else{
        p->r = Rinsert(p->r, key);
    }

    p->height = nodeheight(p);

    if(BalanceFactor(p)>1 && key<p->l->val){
        // LLRrotation
        return LLrotation(p);            // returns the new next child pointer after rotation
    }
    else if(BalanceFactor(p)>1 && key>p->l->val){
        // LRrotation
        return LRrotation(p);
    }
    else if(BalanceFactor(p)<-1 && key>p->r->val){
        // RRrotation
        return RRrotation(p);
    }
    else if(BalanceFactor(p)<-1 && key<p->r->val){
        // RLrotation
        return RLrotation(p);
    }

    return p;
}

int main(){

    root = Rinsert(root, 50);
    Rinsert(root, 10);
    Rinsert(root, 20);
    Rinsert(root, 8);
    Rinsert(root, 6);

    cout<< root->val<<" "<<root->l->val<<" "<<root->r->val<<" "<<root->l->l->val<<" "<<root->l->r->val;
    // Expected: 20, 8, 50, 6, 10

    return 0;
}