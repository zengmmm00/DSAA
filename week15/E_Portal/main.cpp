#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define node_num 500001
#define MAXdistance INT64_MAX
using namespace std;
struct edge{
    ll next=-1;
    ll weight=-1;
    edge(ll n,ll w){next=n,weight=w;}
};

//struct node{
//    ll value = 0;
//    ll distance=MAXdistance;
//    ll parent=-1;
//    vector<edge*> vec;
//    ll through_path;
//};
struct node{
    ll value;
    vector<edge*> vec;
    ll distance=MAXdistance;
    bool isVisit = false;
    bool po = false;
    node(){}
};
node* nodeArr[node_num];

struct bigNode{
    node* newNode;
    ll newDistance = MAXdistance;
//    bigNode(node* n,ll dis){newNode=n;newDistance=dis;}
    ll through_path = 0;
};
bigNode* cap(node * n){
    bigNode * b = new bigNode;
    b->newDistance = n->distance;
    b->newNode = n;
    return b;
}
struct cmp{
    bool operator()(bigNode *a,bigNode* b){
        return a->newDistance > b->newDistance;
    }
};
priority_queue<bigNode*, vector<bigNode*>,cmp> p;



void initial_node(ll n, ll k){
    for (ll i = 1; i <= n; ++i) {
        node* tmp = new node;
//            tmp->through_path = (i-1)%(k+1);
        tmp->value=i;
        nodeArr[i] = tmp;

    }
}

void initial_edge(ll m, ll p, ll k){
    for (ll i = 0; i < m; ++i) {
        ll u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        edge* uv = new edge(v,w);
        nodeArr[u]->vec.push_back(uv);
    }
    for (ll i = 0; i < p; ++i) {
        ll u,v;
        scanf("%lld %lld",&u,&v);
        edge* uv = new edge(v,0);
        nodeArr[u]->vec.push_back(uv);
    }
}

void Dijkstra(ll k, ll n){
    ll s,t;
    scanf("%lld %lld",&s,&t);

    nodeArr[s]->distance=0;
    p.push(cap(nodeArr[s]));

    while (p.top()->newNode->value != t){
        bigNode * start = p.top();
        while(start->newNode->po){
            p.pop();
            start = p.top();
        }
        start->newNode->po = true;
        start->newNode->isVisit = true;
        ll vecSize = start->newNode->vec.size();
        for (ll i = 0; i < vecSize; ++i) {
            ll nextNode = start->newNode->vec[i]->next;

            if(nodeArr[nextNode]->isVisit || (nodeArr[nextNode]->through_path == 0 && start->newNode->vec[i]->weight == 0))continue;
            if(start->newNode->vec[i]->weight == 0)nodeArr[nextNode]->through_path--;
            ll newPath = start->newNode->vec[i]->weight + start->newNode->distance;

            if(nodeArr[nextNode]->distance > newPath ){
                nodeArr[nextNode]->distance = newPath;
                p.push(cap(nodeArr[nextNode]));
            }

        }

    }
    printf("%lld",nodeArr[t]->distance);


}


int main() {
    ll n,m,p,k;
    scanf("%lld %lld %lld %lld",&n,&m,&p,&k);
    initial_node(n,k);
    initial_edge(m, p,k);
    Dijkstra(k, n);
    return 0;
}