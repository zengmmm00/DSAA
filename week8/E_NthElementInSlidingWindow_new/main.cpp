#include <iostream>
using namespace std;
struct node{
    int value;
    int height;
    int size;
    node*left = nullptr;
    node*right = nullptr;
    node(int a,int b){value=a;height=b;size=1;}
};
int m,k;
int sequence[100001];
int position[100001];
int left_height(node*a){
    if(a->left== nullptr)return 0;
    return a->left->height;
}
int right_height(node*a){
    if (a->right== nullptr)return 0;
    return a->right->height;
}
int right_size(node*a){
    if(a->right== nullptr)return 0;
    return a->right->size;
}
int left_size(node*a){
    if(a->left== nullptr)return 0;
    return a->left->size;
}
void set_size(node*a){
    a->size = left_size(a)+right_size(a)+1;
}
//left > right, left_left
node* left_rotation(node *a){
    node*b=a->left;
    int A = left_height(b), B=right_height(b),C=right_height(a);
    a->left = b->right;
    b->right = a;
    a->height = max(B,C) + 1;
    b->height = max(A,a->height) + 1;
    set_size(a);
    set_size(b);
    return b;
}
//left < right, right_right
node* right_rotation(node * &a){//a.left,b.left,b.right
    node*b =a->right;
    int A=right_height(b),B=left_height(b),C=left_height(a);
    a->right = b->left;
    b->left = a;
    a->height = max(B,C)+1;
    b->height = max(A,a->height)+1;
    set_size(a);
    set_size(b);
    return b;
}

void  balance(node*&a){
    int le = left_height(a), ri = right_height(a);
    a->height=max(le,ri)+1;
    if(le-ri>=2){
        int le_le=left_height(a->left),le_ri=right_height(a->left);
        if(le_le>le_ri)a= left_rotation(a);
        else {
            a->left = right_rotation(a->left);
            a=left_rotation(a);
        }
    } else if(ri-le>=2){
        int ri_le=left_height(a->right),ri_ri=right_height(a->right);
        if(ri_ri>ri_le)a=right_rotation(a);
        else{
            a->right = left_rotation(a->right);
            a=right_rotation(a);
        }
    }
    set_size(a);
}
void insert(node*&root,int key){
    root->size++;
    if(key < root->value){
        if(root->left== nullptr){
            node * tmp = new node(key,1);
            root->left = tmp;
        } else{
            insert(root->left,key);
        }
    } else{
        if(root->right== nullptr){
            node * tmp = new node(key,1);
            root->right = tmp;
        }else{
            insert(root->right,key);
        }
    }
    balance(root);
}
void locate(int toFind,node*root,int rank){
    if(toFind==rank){
        printf("%d\n",root->value);}
    else if(toFind<rank){
        locate(toFind,root->left,rank-right_size(root->left)-1);
    } else{locate(toFind,root->right,rank+1+left_size(root->right));}
}
int doDeep(node*&root){
    if(root->left== nullptr){
        int tmp=root->value;
        if(root->right== nullptr){
            delete root;
            root = nullptr;
        } else{
            root=root->right;
        }
        return tmp;
    } else {
        int tmp = doDeep(root->left);
        balance(root);
        return tmp;
    }
}
void del(int toDel,node*&root){
    if(root->value==toDel){
        if(root->left== nullptr&&root->right== nullptr){
            delete root;
            root= nullptr;
        } else if(root->right== nullptr){
            root=root->left;
        } else if(root->left== nullptr){
            root=root->right;
        } else{
            root->value=doDeep(root->right);
        }
    } else{
        if(toDel<root->value)del(toDel,root->left);
        else del(toDel,root->right);
    }
    if(root!= nullptr){
        root->height--;
        balance(root);
    }
}

void transe(node*root){
    if(root->left!= nullptr)transe(root->left);
    printf("%d ",root->value);
    if(root->right!= nullptr)transe(root->right);
}
int main() {
    scanf("%d %d",&m,&k);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&sequence[i]);
    }
    for (int i = 0; i < m - k + 1; ++i) {
        scanf("%d",&position[i]);
    }
    node*root=new node(sequence[0],1);
    for (int i = 1; i < k-1; ++i) {
        insert(root,sequence[i]);
    }
    for (int i = 0; i < m-k+1; ++i) {
        insert(root,sequence[k-1+i]);
        locate(position[i],root,left_size(root)+1);
        del(sequence[i],root);

    }
    return 0;
}