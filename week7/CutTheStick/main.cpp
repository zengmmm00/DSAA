#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
struct node{
    ll value;
    vector<node*> leave;
};
vector<node*> address;
ll total;
void postorder(node * root){
    if(!root->leave.empty())postorder(root->leave[0]);
    if(root->leave.size()==2)postorder(root->leave[1]);
    total+=root->value;
}
bool compare(node *a,node *b){ return a->value<b->value;}
int main() {
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        int N;
        scanf("%d",&N);
        ll length = 0;
        for (int j = 0; j < N; ++j) {
            ll part;
            scanf("%lld",&part);
            length+=part;
            node * tmp = new node{part};
            address.push_back(tmp);
        }
        sort(address.begin(),address.end(),compare);
        while(address.size()>1){
            node * root = new node{address[0]->value+address[1]->value};
            root->leave.push_back(address[0]);
            root->leave.push_back(address[1]);
            vector<node*>::iterator item = address.begin();
            address.erase(item);
            vector<node*>::iterator item2 = address.begin();
            address.erase(item2);
            address.push_back(root);
            sort(address.begin(),address.end(),compare);
        }
        postorder(address[0]);
        vector<node*>::iterator item3 = address.begin();
        address.erase(item3);
        printf("%lld\n",total-length);
        total = 0;
    }
    return 0;
}