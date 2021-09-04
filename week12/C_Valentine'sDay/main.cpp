#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct node{
    int key;
    vector<node*>vec;
    int depth;
    int color;//yellow = 1; red = -1;
    node(){depth=0;color=0;key=0;}
};
node* queue[500010];
int front=0,rear=0;
void enQueue(node* u){
    queue[rear] = u;
    rear++;
}
void deQueue(){
    front++;
}
node*arr[300002];
int n,m;
void bfs(){
    enQueue(arr[1]);
    arr[1]->color=1;
    while (rear!=front){
        node*start = queue[front];
        deQueue();
        for (int i = 0; i < start->vec.size(); ++i) {
            if(start->vec[i]->key==n){
                start->vec[i]->depth= start->depth+1;
                printf("%d",start->vec[i]->depth);
                return;
            } else if(start->vec[i]->color==0){
                start->vec[i]->depth= start->depth+1;
                start->vec[i]->color=1;
                enQueue(start->vec[i]);
            }
        }
        start->color=-1;
    }
    printf("-1");
}
int main() {
    scanf("%d %d",&n,&m);
    for (int i = 1; i <=n; ++i) {
        node*tmp=new node;
        tmp->key=i;
        arr[i]=tmp;
    }
    for (int i = 0; i < m; ++i) {
        int a,b,d;
        scanf("%d %d %d",&a,&b,&d);
        if(d==1){
            arr[a]->vec.push_back(arr[b]);
        } else {
            node *redundancy = new node;
            arr[a]->vec.push_back(redundancy);
            redundancy->vec.push_back(arr[b]);
        }
    }
    bfs();
    return 0;
}