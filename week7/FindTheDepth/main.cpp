#include <iostream>
#include <vector>
#define Size 100002
using namespace std;
struct node{
    int value;
    vector<node> son;
};
node*address[Size];
bool visit[Size];
int depth[Size];
void store(node &a, node &b){
    a.son.push_back(b);
    b.son.push_back(a);
}
void add_address(int a){
    node p;
    p.value = a;
    address[a] = &p;
//    if(address[a]==NULL){
//        node p;
//        p.value = a;
//        address[a] = &p;
//    }
//    if(address[b]==NULL){
//        node p;
//        address[b] = p;
//        address[b]->value=b;
//    }
//    address[a]->son.push_back(*address[b]);
//    address[b]->son.push_back(*address[a]);
}
int count = 0;
void sou(node &root){
    if(!visit[root.value]){
        depth[root.value] = count;
        visit[root.value] = true;
        if(!root.son.empty()){
            count++;
            for (int i = 0; i < root.son.size(); ++i) {
                sou(root.son[i]);
            }
        } else count=1;
    }
}
int main() {
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        int N;
        scanf("%d",&N);
        node w;
        w.value = 1;
        address[1] = &w;
        for (int j = 0; j < N-1; ++j) {
            int a,b;
            scanf("%d %d",&a,&b);
//            add_address(a,b);
            if(address[a]== nullptr){
                node p;
                p.value = a;
                add_address(a);
            }
            if(address[b]== nullptr)add_address(b);
            store(*address[a],*address[b]);
        }
        sou(*address[1]);
        printf("0");
        for (int k = 2; k <= N; ++k) {
            printf(" %d",depth[k]);
        }
        printf("\n");

    }
    return 0;
}