#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
struct edge{
    ll next_x=-1;
    ll next_y=-1;

    ll weight=-1;
    edge(ll x,ll y ,ll w){next_x=x;next_y=y;weight=w;}
};

struct node{
    ll x;
    ll y;
    ll value;
    vector<edge*> vec;
    ll distance=0;
    bool isVisit = false;
    bool po = false;
    node(ll a,ll b,ll v){x=a;y=b;value = v;}
    node(){}
};
struct bigNode{
    node* newNode;
    ll newDistance = 0;
//    bigNode(node* n,ll dis){newNode=n;newDistance=dis;}
};
bigNode* cap(node* n){
    bigNode * b = new bigNode;
    b->newDistance = n->distance;
    b->newNode = n;
    return b;
}
struct cmp{
    bool operator()(bigNode *a,bigNode* b){
        return a->newDistance<b->newDistance;
    }
};
priority_queue<bigNode*, vector<bigNode*>,cmp> p;

int main() {
    ll n,m;
    scanf("%lld %lld",&n,&m);
    node*matrix[n][m];
    ll max_x = 0;
    ll max_y = 0;
    ll max_value = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            ll num;
            scanf("%lld",&num);
            node * tmp = new node(i,j,num);
            matrix[i][j] = tmp;
            if(num > max_value){
                max_x = i;
                max_y = j;
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; ++j) {
            if(i-1 >= 0){//up
                edge*tmp = new edge(i-1,j,matrix[i-1][j]->value * matrix[i][j]->value);
                matrix[i][j]->vec.push_back(tmp);
            }
            if(i+1 < n){//down
                edge*tmp = new edge(i+1,j,matrix[i+1][j]->value * matrix[i][j]->value);
                matrix[i][j]->vec.push_back(tmp);
            }
            if(j-1 >= 0){//left
                edge*tmp = new edge(i,j-1,matrix[i][j-1]->value * matrix[i][j]->value);
                matrix[i][j]->vec.push_back(tmp);
            }
            if(j+1 <m){//right
                edge*tmp = new edge(i,j+1,matrix[i][j+1]->value * matrix[i][j]->value);
                matrix[i][j]->vec.push_back(tmp);
            }
        }
    }

    ll total = 0;
    
    matrix[max_x][max_y]->distance = 0;
    p.push(cap(matrix[max_x][max_y]));

    for (ll j = 0; j < n*m; ++j) {
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
            ll nextNode_x = start->newNode->vec[i]->next_x;
            ll nextNode_y = start->newNode->vec[i]->next_y;

            if(matrix[nextNode_x][nextNode_y]->isVisit)continue;

            ll newPath = start->newNode->vec[i]->weight;
            if(matrix[nextNode_x][nextNode_y]->distance < newPath){
                matrix[nextNode_x][nextNode_y]->distance = newPath;
//                bigNode* tmp = new bigNode(matrix[nextNode],newPath);
                p.push(cap(matrix[nextNode_x][nextNode_y]));
            }
        }
    }

    printf("%lld",total);
    return 0;
}