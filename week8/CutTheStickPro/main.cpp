#include <iostream>
#include <array>
#include <cmath>
#define ll long long
using namespace std;
ll arr[100005];
ll n;
void rootFix(ll u){
    while(true){
        if(2*u>n)break;//leaf
        ll small = 2*u;
        if(2*u+1<=n&&arr[2*u+1]<arr[2*u]){
            small=2*u+1;
        }
        if(arr[u]>arr[small]){
            ll tmp = arr[u];
            arr[u] = arr[small];
            arr[small] = tmp;
            u=small;
        } else break;
    }
}
void build(){
    for (ll i = n; i >= 1; --i) {
        rootFix(i);
    }
}
ll deleteMin(){
    ll root = arr[1];
    arr[1] = arr[n];
    n--;
    rootFix(1);
    return root;
}
void insert(ll e){
    n++;
    arr[n]=e;
    ll i = n;
    while(i/2>=1&&arr[i]<=arr[i/2]){
        ll tmp = arr[i];
        arr[i] = arr[i/2];
        arr[i/2] = tmp;
        i = i/2;
    }
}
int main() {
    ll T;
    scanf("%lld",&T);
    for (ll i = 0; i < T; ++i) {
        scanf("%lld",&n);
        for (ll j = 1; j <= n; ++j) {
            scanf("%lld",&arr[j]);
        }
        build();
        ll answer = 0;
        while(n>1){
            ll a = deleteMin();
            ll b = deleteMin();
            answer = answer+a+b;
            insert(a+b);
        }
        printf("%lld\n",answer);
    }
    return 0;
}
