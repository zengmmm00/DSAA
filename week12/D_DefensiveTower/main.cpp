#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct node{
    int key;
    vector<node*>vec;
    int depth;
    int color;//yellow = 1; red = -1;
    bool tower;
    node(){depth=0;color=0;key=0;tower=false;}

};
int front=0,rear=0;
node* queue[300];
void enQueue(node* u){
    queue[rear] = u;
    rear++;
}
void deQueue(){
    front++;
}
node*arr[300000];
int n;//# of node
int m;//# of undirected road
bool cmp(node *a,node*b){
    return a->vec.size()>b->vec.size();
}
//void bfs(){
//    vector<int> toBuild;
//    int tower_num=0;
//    enQueue(arr[1]);
//    arr[1]->color=1;
//
//    while (rear!=front){
//        node*star = queue[front];
//        deQueue();
//        printf("%d\n",star->key);
//        bool cover=false;
//
//        for (int i = 0; i < star->vec.size(); ++i) {
//            if(star->vec[i]->tower){
//                cover=true;
//            }
//            if(star->vec[i]->color==0){
//                enQueue(star->vec[i]);
//                star->vec[i]->color=1;
//            }
//        }
//        star->color=-1;
//
//        if(!cover&&!star->tower){
//            sort(queue,queue+rear-front,cmp);
//            if(star->vec.size()>=queue[front]->vec.size()){
//                star->tower=true;
//                toBuild.push_back(star->key);
//            } else{
//                queue[front]->tower=true;
//                toBuild.push_back(queue[front]->key);
//
//            }
//            tower_num++;
//        }
//    }
//
//    printf("%d\n",tower_num);
//    for (int j = 0; j < toBuild.size(); ++j) {
//        printf("%d ",toBuild[j]);
//    }
//    printf("\n");
//}
void bfs(){
    vector<int> toBuild;
    int tower_num=0;
    arr[1]->color=1;
    enQueue(arr[1]);
    while(rear!=front){
        node*tmp = queue[front];
        deQueue();
        bool cover = false;
        if(tmp->tower)cover=true;
        for (int i = 0; i < tmp->vec.size(); ++i) {
            if(tmp->vec[i]->tower){
                cover=true;
            }
            if(tmp->vec[i]->color==0){
                tmp->vec[i]->color=1;
                enQueue(tmp->vec[i]);
            }
        }
        tmp->color=-1;
        if(!cover){
            tower_num++;
            sort(tmp->vec.begin(),tmp->vec.end(),cmp);
            node*newTower=tmp;
            if(tmp->vec.size()<tmp->vec[0]->vec.size()){
                newTower = tmp->vec[0];
            }
            newTower->tower=true;
            toBuild.push_back(newTower->key);
        }
    }
    printf("%d\n",tower_num);
    for (int j = 0; j < toBuild.size(); ++j) {
        printf("%d ",toBuild[j]);
    }
    printf("\n");
}
int main() {
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        front=0,rear=0;
        scanf("%d %d",&n,&m);
        for (int j = 0; j < m; ++j) {
            int a,b;
            scanf("%d %d",&a,&b);
            if(arr[a]== NULL){
                node * na = new node;
                arr[a]=na;
                arr[a]->key=a;
            }
            if(arr[b]==NULL){
                node*nb=new node;
                arr[b]=nb;
                arr[b]->key=b;
            }
            arr[a]->vec.push_back(arr[b]);
            arr[b]->vec.push_back(arr[a]);
        }

        bfs();

        for (int j = 0; j <= n; ++j) {
            if(arr[j]!= NULL){
                delete arr[j];
                arr[j]=NULL;
            }
        }

    }
    return 0;
}