#include <iostream>
#define ll long long
using namespace std;
ll arr[1002];
ll n;//number of node on the tree
void insert(ll e){
    n++;
    arr[n]=e;
    ll i = n;
    while(i/2>=1&&arr[i]<=arr[i/2]){
        swap(arr[i] , arr[i/2]);
        i = i/2;
    }
}
void rootFix(ll u){
    while(true){
        if(2*u>n)break;//leaf
        ll small = 2*u;
        if(2*u+1<=n&&arr[2*u+1]<arr[2*u]){
            small=2*u+1;
        }
        if(arr[u]>arr[small]){
            swap(arr[u] , arr[small]);
            u=small;
        } else break;
    }
}
ll a(ll in){
  ll ans  = in;
  ll i = in;
  while(i!=0){
      ans+=i%10;
      i=(i-i%10)/10;
  }
    return ans;
}
int main() {
    ll t;
    scanf("%lld",&t);
    ll k;
    scanf("%lld",&k);
    ll s;
    scanf("%lld",&s);
    for (ll i = 1; i <= t; i++) {
        ll tmp = a(i+s);
        if(n < k){
            insert(tmp);
        } else if(tmp > arr[1]){
            arr[1] = tmp;
            rootFix(1);
        }
        if(0 == i % 100){
            s = arr[1];
            printf("%lld ",s);
        }
    }
    return 0;
}