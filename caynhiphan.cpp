#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
class tree{
    private:
        int key;
        tree *next, *back;
    public:
        friend class listtree; 
};
class listtree{
    private:
        tree *root;
    public:
        tree* khoitaonode(int);
        tree* timkiem(int);
        tree* findinsert(int);
        void insertnode();
        void createtree_();
        void NLR(tree* root);
        friend class tree;
};

tree* listtree::khoitaonode(int x){
    tree* n=new tree();
    n->key=x;
    n->next=n->back=NULL;
    return n;
}
tree* listtree::timkiem(int x){
    if(root==NULL){
        return NULL;
    }
    tree* b = root;
    while(b != NULL){
        if(b->key == x)
            return b;
        else if(b->key > x)
            b = b->back;
        else 
            b = b->next;
    }
}
tree* listtree::findinsert(int x){
    if(root == NULL){
        return NULL;
    }
    tree* p = root;
    tree *f = p;
    while(p != NULL){
        f = p;
        if(p->key>x)
        {
            p = p->back;
        }
        else{
            p = p->next;
        }  
    }
    return f;  
}
void listtree::insertnode(){
    int x;
    tree *n;
    n =khoitaonode(x);
    if(root == NULL){
        root=n;
        return;
    }
    tree* f=findinsert(x);
    if(f!=NULL){
        if(f->key > x)
            f->back = n;
        else
            f->next = n;
    }
}
void listtree::createtree_(){
    int n;
    for(int i=0; i<n; i++){
        insertnode();
    }
}
void listtree::NLR(tree* root){
    if(root != NULL){
        cout<<root->key<<"\t";
        NLR(root->back);
        NLR(root->next);
    }
}
int main(){

    return 0;
}
