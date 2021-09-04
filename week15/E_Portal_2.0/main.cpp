#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define node_num 5000000
#define MAXdistance INT64_MAX
using namespace std;
struct edge{
    ll next=-1;
    ll weight=-1;
    edge(ll n,ll w){next=n,weight=w;}
};
struct node{
    ll value;
    vector<edge*> vec;
    node(){}
};
struct node_path{
    ll value_p;
    node* original;
    ll path = 0;//have pass "path" roads
    ll distance=MAXdistance;
    bool isVisit = false;
    bool po = false;

};
node* nodeArr[node_num];

node_path* nodeArr_path[node_num];
struct bigNode{
    node_path* node_path_big;
    ll newDistance = MAXdistance;
};
bigNode* cap(node_path * n){
    bigNode * b = new bigNode;
    b->newDistance = n->distance;
    b->node_path_big = n;
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
        tmp->value=i;
        nodeArr[i] = tmp;
        for (ll j = 0; j <= k; ++j) {
            node_path * t = new node_path;
            t->original = tmp;
            t->value_p = (i-1) * (k + 1) + j;
            nodeArr_path[(i-1) * (k + 1) + j] = t;
        }
    }
}
void initial_edge(ll m, ll p){
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
void Dijkstra(ll k){
    ll s,t;
    scanf("%lld %lld",&s,&t);
    node_path * nap=nodeArr_path[(s-1) * (k + 1) + 0];
    nap->distance=0;

    p.push(cap(nap));
    while(p.top()->node_path_big->original->value != t){
        bigNode * start_b = p.top();
        node_path * start_p = start_b->node_path_big;
        node * start_o = start_p->original;
        while(start_p->po){
            p.pop();
            start_b = p.top();
            start_p = start_b->node_path_big;
            start_o = start_p->original;
        }
        start_p->po = true;
        start_p->isVisit = true;
        ll vecSize = start_o->vec.size();
        ll have_through = start_p->path;
        for (ll i = 0; i < vecSize; ++i) {
            ll nextNode = start_o->vec[i]->next;
            if(start_o->vec[i]->weight == 0){
                if(have_through == k){
                    continue;
                } else{
                    nodeArr_path[(nextNode - 1)* (k+1) + have_through+1]->distance = start_p->distance;
                    nodeArr_path[(nextNode - 1)* (k+1) + have_through+1]->path = start_p->path + 1;
                    p.push(cap(nodeArr_path[(nextNode - 1)* (k+1) + have_through+1]));
                }
            } else{
                ll newpath= start_o->vec[i]->weight + start_p->distance;
                if(nodeArr_path[(nextNode - 1)*(k + 1) + have_through]->distance > newpath){
                    nodeArr_path[(nextNode - 1)*(k + 1) + have_through]->distance = newpath;
                    nodeArr_path[(nextNode - 1)*(k + 1) + have_through]->path = have_through;
                    p.push(cap(nodeArr_path[(nextNode - 1)*(k + 1) + have_through]));
                }
            }
        }
    }
    printf("%lld",p.top()->newDistance);
}
int main() {
    ll n,m,p,k;
    scanf("%lld %lld %lld %lld",&n,&m,&p,&k);
    initial_node(n,k);
    initial_edge(m, p);
    Dijkstra(k);
    return 0;
}