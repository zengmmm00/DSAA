#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
struct node{
    int value;
    int pre_index;
    int in_index;
    node * left;
    node * right;
    node * root;
};
node * address[1002];
bool check(node* toFind, int j){
    if(toFind->root!= nullptr&&j == toFind->root->in_index)return false;
    if(toFind->root!= nullptr&&toFind->root->root!= nullptr&&(j==toFind->root->in_index||j==toFind->root->root->in_index))return false;
    return true;
}
void postorderprint(node *root){
    if(root->left!= nullptr)
        postorderprint(root->left);
    if(root->right!= nullptr)
        postorderprint(root->right);
    printf("%d ",root->value);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int a = 0; a < T; ++a) {
        int N;
        scanf("%d",&N);
        int pre[N];
        int in[N];
        for (int b = 1; b <= N; ++b) {
            node * p = new node{b};
            address[b]=p;
        }
        for (int b = 0; b < N; ++b) {
            scanf("%d",&pre[b]);
            address[pre[b]]->pre_index = b;
        }
        for (int b = 0; b < N; ++b) {
            scanf("%d",&in[b]);
            address[in[b]]->in_index = b;
        }
        if(N == 1)printf("1\n");
        else{
            int i = 0;
            for (int p = 1; p < N; ++p) {
                node * r = address[pre[i]];
                bool found = false;
                node * toFind = address[pre[p]];
                int j = r->in_index-1;
                //go left
                while(j>=0&&address[in[j]]->right== nullptr&&address[in[j]]->left== nullptr){
                    if(in[j]==toFind->value){
                        r->left = toFind;
                        toFind->root = r;
                        found=true;
                        break;
                    }
                    j--;
                }
                if(found){
                    i=p;
                    continue;
                }
                //go right
                j = r->in_index+1;
                while(j<=N-1&&address[in[j]]->left== nullptr&&address[in[j]]->right== nullptr){
                    if(in[j]==toFind->value){
                        r->right = toFind;
                        toFind->root = r;
                        found=true;
                        break;
                    }
                    j++;
                }
                if(found){
                    i=p;
                    continue;
                }
                p--;
                i=r->root->pre_index;
            }
            postorderprint(address[pre[0]]);
            if(a!=T-1)printf("\n");
        }
    }
    return 0;
}