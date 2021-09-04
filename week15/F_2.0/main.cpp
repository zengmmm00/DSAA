#include <iostream>
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

ll LR[1010];
stack<ll> s1;
stack<ll> s2;

ll x[1010];
ll y[1010];
ll r[1010];
ll t[1010];

ll strong[1010] = {0};
ll total = 0;

void connect(ll n){
    for (ll i = 0; i < n; ++i) {
        scanf("%lld %lld %lld %lld", &x[i],&y[i],&r[i],&t[i]);
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            ll dis = pow((x[i] - x[j]),2) + pow((y[i] - y[j]),2);
            if(i != j && dis <= pow(r[i],2)){
                graph[i].push_back(j);
                r_graph[j].push_back(i);
            }
        }
    }
//    ll m;
//    scanf("%lld",&m);
//    for (ll i = 0; i < m; ++i) {
//        ll u,v;
//        scanf("%lld %lld",&u,&v);
//        graph[u].push_back(v);
//        r_graph[v].push_back(u);
//    }
//    for (ll j = 0; j < n; ++j) {
//        scanf("%lld",&t[j]);
//    }
}

void dfs1(ll n){
    ll count = 0;
    while (count < n){
        if(s1.empty()){
            for (ll i = 0; i < n; ++i) {
                if(r_color[i] == 0){
                    s1.push(i);
                    r_color[i] = 1;
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
            LR[count] = root;
            count++;
        }
    }
}

struct suo{
    ll small = INT64_MAX;
    bool ru = false;
};

void dfs2(ll n){
    ll start ;
    ll group = 0;
    ll count = 0;
//    bool ru = false;
//    ll small = INT64_MAX;
    ll lrc = 0;
    while (lrc < n){
        if(s2.empty()){
//            small = INT64_MAX;
//            ru = false;
            count = 0;
            for (ll i = n-1; i >=0; --i) {
                if(color[LR[i]] == 0){
                    s2.push(LR[i]);
                    break;
                }
            }


            color[s2.top()] = 1;
            group++;
        }
        start = s2.top();
        strong[start] = group;
        bool found = false;
        for (ll i = 0; i < graph[start].size(); ++i) {
            if(color[graph[start][i]] == 0){
                s2.push(graph[start][i]);
                color[graph[start][i]] = 1;
                found = true;
                break;
            }
        }
        if(!found){
            lrc++;
            color[start] = -1;
            s2.pop();
            strong[start] = group;
            count++;
//            if(t[start] < small){
//                small = t[start];
//            }
//
//            if(!ru){
//                for (ll i = 0; i < r_graph[start].size(); ++i) {
//                    if(strong[r_graph[start][i]] != group){
//                        ru = true;
//                        break;
//                    }
//                }
//            }



        }
//        if(s2.empty() && !ru){
//            total += small;
//        }
    }
    suo sc[group+1];
    for (ll i = 0; i < n; ++i) {
        if(t[i] < sc[strong[i]].small){
            sc[strong[i]].small = t[i];
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < r_graph[i].size(); ++j) {
            if(strong[r_graph[i][j]] != strong[i]){
                sc[strong[i]].ru = true;
                break;
            }
        }
    }
    for (ll i = 1; i <= group; ++i) {
        if(!sc[i].ru){
            total+= sc[i].small;
        }
    }
}

int main() {
    ll n;
    scanf("%lld",&n);
    connect(n);
    dfs1(n);
    dfs2(n);
    printf("%lld",total);
    return 0;
}