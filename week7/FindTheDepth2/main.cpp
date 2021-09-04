#include <iostream>
#include <vector>
#define Size 100002
using namespace std;
struct node{
    int value;
    vector<node*> son;
};
node*address[Size];
bool visit[Size];
int depth[Size];
void add_address(int a){
    if(address[a] == NULL){
        node *p = new node;
        p->value = a;
        address[a] = p;
    }
}
void store(node*c,node*d){//d is c's son
    c->son.push_back(d);
}
int count=0;
int N = 0;
void sou(node *p){
    if(!visit[p->value]){
        depth[p->value] = count;
        visit[p->value] = true;
        if(p->son.size()!=1||count==0){
            count++;
            for (int i = 0; i < p->son.size(); ++i) {
                sou(p->son[i]);
                count = depth[p->value]+1;
            }
        }
    }
}
int main() {
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        scanf("%d",&N);
        add_address(1);
        for (int j = 0; j < N-1; ++j) {
            int a,b;
            scanf("%d %d",&a,&b);
            add_address(a);
            add_address(b);
            store(address[a],address[b]);
            store(address[b],address[a]);
        }
        sou(address[1]);
        printf("0");
        for (int k = 2; k <= N; ++k) {
            printf(" %d",depth[k]);
            address[k] = NULL;
            visit[k]=false;
        }
        printf("\n");
        count = 0;
        address[1] = NULL;
        visit[1]=false;
    }
        return 0;
}