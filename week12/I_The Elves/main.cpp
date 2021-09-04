#include <iostream>
#define ll long long
#include <vector>
#include <stack>
#include <queue>
#define mod 1000000007
#define MAX 100002
using namespace std;
ll aa[MAX];
ll bb[MAX];
vector<ll> vec[MAX];
ll dp[MAX];

void in(ll n){
    for (ll i = 1; i <= n; ++i) {
        dp[i] = -1;
        scanf("%lld %lld",&aa[i],&bb[i]);
    }
}



void connect(ll m){
    for (ll i = 0; i < m; ++i) {
        ll u,v;
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
    }
}

void dfs(ll start){
    if(dp[start]!=-1)return;
    dp[start]=0;
    for (ll i = 0; i < vec[start].size(); ++i) {
        dfs(vec[start][i]);
        dp[start] += (bb[vec[start][i]] + dp[vec[start][i]])%mod;
    }
}

ll ans(ll n){
   ll answer = 0;
    for (ll i = 1; i <= n; ++i) {
        answer += (aa[i] * dp[i]) % mod;
    }
    answer = answer % mod;
    return answer;
}



int main() {
    ll T;
    scanf("%lld",&T);
    for (ll i = 0; i < T; ++i) {
        ll n,m;
        scanf("%lld %lld",&n,&m);
        in(n);
        connect(m);
        for (ll j = 1; j <= n; ++j) {
            dfs(j);
        }
        printf("%lld\n",ans(n));
        for (ll k = 1; k <= n; ++k) {
            vec[k].clear();
            vector<ll>().swap(vec[k]);
            dp[k]=-1;
        }
    }
    return 0;
}