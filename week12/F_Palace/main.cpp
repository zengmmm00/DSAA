#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int parent=0;
    int key;
    int a;
    int b;
    int ru =0;
    vector<node*>vec;
    int next(){
        return parent+key;
    }
};
bool cmp(node*i,node*j){//i on j return true
    return (i->a < j->a && i->b < j->b) || (i->a < j->b && i->b < j->a);
}

node* arr[3000];

void in(int n){
    for (int j = 0; j < n; ++j) {
        node*tmp=new node;
        scanf("%d %d %d",&tmp->a,&tmp->b,&tmp->key);
        arr[j]=tmp;
    }
}

void buildGraph(int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(cmp(arr[i],arr[j])){
                arr[j]->vec.push_back(arr[i]);
                arr[i]->ru++;
            }
        }
    }
}

queue<node*> q;

void findNoRu(int n){
    for (int i = 0; i < n; ++i) {
        if(arr[i]->ru==0)q.push(arr[i]);
    }
}

priority_queue<int>pq;

void topological(){
    while (!q.empty()){
        node*tmp = q.front();
        q.pop();
        if(tmp->vec.empty()){
            pq.push(tmp->next());
            continue;
        }
        for (int i = 0; i < tmp->vec.size(); ++i) {
            tmp->vec[i]->ru--;
            if(tmp->vec[i]->ru==0)
            {
                q.push(tmp->vec[i]);
            }
            tmp->vec[i]->parent = max(tmp->vec[i]->parent,tmp->next());
        }
    }
}

void clean(int n){
    while(!pq.empty())pq.pop();
    while(!q.empty())q.pop();
    for (int i = 0; i < n; ++i) {
        delete arr[i];
        arr[i] = NULL;
    }
}

int main() {
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d",&n);
        in(n);
        buildGraph(n);
        findNoRu(n);
        topological();
        printf("%d\n",pq.top());
        clean(n);
    }
    return 0;
}