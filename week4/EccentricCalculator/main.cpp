#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
ll digit(ll q, ll n){
    ll p = (ll)log10(q) + 1;//digit of q
    if(p<n){ return q;}
    return q / (ll)(pow(10, p-n));
}
int main() {
   int T;
   scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        ll n =0;
        ll m =0;
        scanf("%lld",&n);
        scanf("%lld",&m);

        ll count=0 ,s1=0,s2=0,circleLength =0;
        ll max= digit(m,n), a= digit(m,n), b = digit(m,n);

        ll *step=&s1;
        while(true){
            *step++;
            a = digit(pow(a,2),n);
            b = digit(pow(b,2),n);
            b = digit(pow(b,2),n);

            if(a>max){
                max = a;
            }
            if(a == b){
                if(count == 1){
                    circleLength = s1 - s2;
                    break;
                } else{
                    count++;
                    step = &s2;
                }
            }
        }
        step = nullptr;
        for (int j = 0; j < circleLength; ++j) {
            a = digit((ll)pow(a,2),n);
            if(a>max){
                max=a;
            }
        }
        printf("%lld\n", max);
    }
    return 0;
}