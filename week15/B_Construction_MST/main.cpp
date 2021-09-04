#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define node_num 1001
using namespace std;

struct edge{
    ll next=-1;
    ll weight=-1;
    edge(ll n,ll w){next=n,weight=w;}
};

struct node{
    ll value = 0;
    ll distance=INT64_MAX;
    ll parent=-1;
    bool isVisit = false;
    bool po = false;
    vector<edge*> vec;
};

node* nodeArr[node_num];
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
struct bigNode{
    node* newNode;
    ll newDistance;
//    bigNode(node* n,ll dis){newNode=n;newDistance=dis;}
};
struct cmp{
    bool operator()(bigNode *a,bigNode* b){
        return a->newDistance>b->newDistance;
    }
};
priority_queue<bigNode*, vector<bigNode*>,cmp> p;

bigNode* cap(node* n){
    bigNode * b = new bigNode;
    b->newDistance = n->distance;
    b->newNode = n;
    return b;
}

ll Prim(ll n){
    nodeArr[1]->distance = 0;
    p.push(cap(nodeArr[1]));
    ll total = 0;
    for(ll j = 0; j< n;++j){
        bigNode* start = p.top();
        while(start->newNode->po){
            p.pop();
            start = p.top();
        }

        start->newNode->po = true;
        total+=start->newDistance;
        start->newNode->isVisit = true;
        ll vecSize = start->newNode->vec.size();
        for (ll i = 0; i < vecSize; ++i) {
            ll nextNode = start->newNode->vec[i]->next;
            if(nodeArr[nextNode]->isVisit)continue;

            ll newPath = start->newNode->vec[i]->weight;
            if(nodeArr[nextNode]->distance > newPath){
                nodeArr[nextNode]->distance = newPath;
//                bigNode* tmp = new bigNode(nodeArr[nextNode],newPath);
                p.push(cap(nodeArr[nextNode]));
            }
        }

    }

    return total;
}



int main() {
    ll n,m;
    scanf("%lld %lld",&n,&m);
    initial_node(n);
    initial_edge(m);
    printf("%lld",Prim(n));
    return 0;
}