#include <iostream>
using namespace std;

struct node{
    node *left = nullptr;
    node *right = nullptr;
    int value = 0;
    int size=1;
//    node(){
//        left = new node;
//        right = new node;
//    }
};
node *root = new node;
void insert(int e){
    node *u = root;
    node *tmp = new node;
    tmp->value = e;
    while(true){
        u->size++;
        if(e < u->value){
            if(u->left != nullptr){
                u = u->left;
            } else{
                u->left = tmp;
                break;
            }
        } else{
            if(u->right!= nullptr){
                u = u->right;
            } else{
                u->right = tmp;
                break;
            }
        }
    }

}
//left > right, left_left
void left_rotation(node *a,node *b,node *A,node *B,node*C){//b.left,b.right,a.right
    b->right = a;
    a->left = B;
    a->right = C;
    a->size = B->size + C->size;
    b->size = A->size + a->size;
}
//left < right, right_right
void right_rotation(node *a,node *b,node *A,node *B,node*C){//a.left,b.left,b.right
    a->right = B;
    b->left = a;
    b->right = C;
    a->size = A->size + B->size;
    b->size = a->size + C->size;
}
void balance(node *a){

    if(a->left->size - a->right->size >=2){
        node *b = a->left;
        if(b->left->size > b->right->size){
            left_rotation(a,b,b->left,b->right,a->right);
            root=b;
        } else{
            node *c =b->right;
            a->left = c;
            right_rotation(b,c,b->left,c->left,c->right);
            left_rotation(a,c,c->left,c->right,a->right);
            root=c;
        }
    } else if(a->right->size - a->left->size >=2){
        node * b = a->right;
        if(b->right->size > b->left->size){
            right_rotation(a,b,a->left,b->left,b->right);
            root=b;
        } else{
            node *c = b->left;
            a->right = c;
            left_rotation(b,c,c->left,c->right,b->right);
            right_rotation(a,c,a->left,c->left,c->right);
            root=c;
        }
    }
}
int m,k;
int search(int r){
    node *u = root;
    while(true){
        if(r == k - u->right->size){ return u->value;}
        else if(r <= k-u->right->size){
            u = u->left;
        } else u = u->right;
    }
}
node* predecessor(int q){
    node *u = root;
    while(u->size!=0 && u->value !=q){
        if(q < u->value)u = u->left;
        else u = u->right;
    }
    return u;
}
void dele(node *remov,int val){
    remov->size--;
    if(remov->value<val){
        dele(remov->right,val);
    } else if (remov->value>val){
        dele(remov->left,val);
    } else{
        if(remov->size == 1){delete remov;remov = nullptr;}
        else if (remov->left !=nullptr && remov->right == nullptr){
            remov = remov->left;
        } else if(remov->right !=nullptr&&remov->left==nullptr){
            remov = remov->right;
        }else{
            node *tmp = remov->right;
            while(tmp->left!= nullptr){
                tmp = tmp->left;
            }
            remov->value = tmp->value;
            dele(remov->right,tmp->value);
        }
    }

}
int number[100002];
int ran[100002];
int main() {
    scanf("%d %d",&m,&k);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&number[i]);
    }
    for (int i = 0; i < m-k+1; ++i) {
        scanf("%d",&ran[i]);
    }
    root->value = number[0];

    for (int i = 1; i < k-1; ++i) {
        insert(number[i]);
        balance(root);
    }
    for (int i = 0; i < m - (k-1); ++i) {
        insert(number[i+k-1]);
        balance(root);
        printf("%d\n",search(ran[i]));
        dele(root,number[i]);
        balance(root);
    }
    return 0;
}