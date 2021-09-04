#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define node_num 1001
#define MAXdistance 8000000000000000
using namespace std;
struct edge{
    ll next=-1;
    ll weight=-1;
    edge(ll n,ll w){next=n,weight=w;}
};

struct node{
    ll value = 0;
    ll distance=MAXdistance;
    ll parent=-1;
    vector<edge*> vec;
};

node* nodeArr[node_num];

bool cmp(const node*a,node*b){
    return a->distance>b->distance;//
}
vector<node*> minHeap;

void initial_node(ll n){
    for (ll i = 1; i <= n; ++i) {
        node* tmp = new node;
        tmp->value=i;
        nodeArr[i] = tmp;

    }
}

void initial_edge(ll m){
    for (ll i = 0; i < m; ++i) {
        ll u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        edge* uv = new edge(v,w);
        nodeArr[u]->vec.push_back(uv);
        edge* vu = new edge(u,w);
        nodeArr[v]->vec.push_back(vu);
    }
}

void output(ll a, ll s,ll t){
    if(a == s){
        printf("%lld -> ",a);
        return;
    }else{
        output(nodeArr[a]->parent,s,t);
        printf("%lld ",a);
        if(a != t)printf("-> ");
    }
}

ll Dijkstra(ll s, ll t, ll n){
    nodeArr[s]->distance=0;
    ll start = s;
    for (ll i = 1; i <= n; ++i) {
        minHeap.push_back(nodeArr[i]);
    }
    while(start!=t){
        sort(minHeap.begin(),minHeap.end(),cmp);//
        start = minHeap.back()->value;//
        if(nodeArr[start]->distance == MAXdistance) {
            return -1;
        }
        minHeap.pop_back();//
        ll vecSize = nodeArr[start]->vec.size();
        for (ll i = 0; i < vecSize; ++i) {
            ll nextNode = nodeArr[start]->vec[i]->next;
            ll newPath = nodeArr[start]->vec[i]->weight + nodeArr[start]->distance;
            if(nodeArr[nextNode]->distance > newPath ){
                nodeArr[nextNode]->parent = start;
                nodeArr[nextNode]->distance = newPath;
            }
        }

    }
    printf("The shortest path is ");
    output(t,s,t);
    return nodeArr[t]->distance;
}

int main() {
    ll n,m;
    scanf("%lld",&n);
    scanf("%lld",&m);
    initial_node(n);
    initial_edge(m);
    ll s,t;
    scanf("%lld %lld",&s,&t);
    printf("\nThe length of shortest path is %lld",Dijkstra(s,t,n));
    return 0;
}