#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

#define ll long long
using namespace std;

vector<ll> graph[1010];
vector<ll> r_graph[1010];

ll color[1010] = {0};//white = 0; yellow = 1; red = -1;
ll r_color[1010] = {0};//white = 0; yellow = 1; red = -1;

stack<ll> LR;
stack<ll> s1;
stack<ll> s2;

ll x[1010];
ll y[1010];
ll r[1010];
ll t[1010];

void dfs1(ll n){
    r_color[1] = 1;
    s1.push(1);
    while (LR.size() < n){
        if(s1.empty()){
            for (ll i = 1; i <= n; ++i) {
                if(r_color[i] == 0){
                    s1.push(i);
                    break;
                }
            }
        }
        ll root = s1.top();
        bool found = false;
        for (ll i = 0; i < r_graph[root].size(); ++i) {
            if(r_color[r_graph[root][i]] == 0){
                s1.push(r_graph[root][i]);
                r_color[r_graph[root][i]] = 1;
                found = true;
                break;
            }
        }
        if(!found){
            r_color[root] = -1;
            s1.pop();
            LR.push(root);
        }
    }
}

ll strong[1010] = {0};
ll total = 0;
bool sc[1010];

void dfs2(){
    color[LR.top()] = 1;
    s2.push(LR.top());
    ll count = 1;
    sc[LR.top()] = true;
    while (!LR.empty()){
        ll root = s2.top();
        bool found = false;
        if(color[root] == 0)color[root] = 1;
        for (ll i = 0; i < graph[root].size(); ++i) {
            if(color[graph[root][i]] == 0){
                s2.push(graph[root][i]);
                color[graph[root][i]] = 1;
                found = true;
                break;
            }
        }
        if(!found){
                LR.pop();
                color[root] = -1;
                strong[count] = root;
                sc[root] = true;
                count++;
            s2.pop();
        }
        if(s2.empty()){
            bool ru = false;
            for (ll i = 1; i < count; ++i) {
                ll check = strong[i];
                for (ll j = 0; j < r_graph[check].size(); ++j) {
                    if(!sc[r_graph[check][j]]){
                        ru = true;
                        break;
                    }
                }
                if(ru)break;
            }
            if(!ru){
                ll small = INT64_MAX;
                for (ll i = 1; i < count; ++i) {
                    if(t[strong[i]] < small){
                        small = t[strong[i]];
                    }
                }
                total += small;
            }
            for (ll k = 1; k < count; ++k) {
                sc[strong[k]] = false;
            }
            count = 1;
            if(!LR.empty()){
                s2.push(LR.top());
            }
        }
    }

}

void connect(ll n){
    for (ll i = 1; i <= n; ++i) {
        scanf("%lld %lld %lld %lld", &x[i],&y[i],&r[i],&t[i]);
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            ll dis = pow((x[i] - x[j]),2) + pow((y[i] - y[j]),2);
            if(i != j && dis <= pow(r[i],2)){
                graph[i].push_back(j);
                r_graph[j].push_back(i);
            }
        }
    }
}

int main() {
    ll n;
    scanf("%lld",&n);
    connect(n);
    dfs1(n);
    dfs2();
    printf("%lld",total);
    return 0;
}