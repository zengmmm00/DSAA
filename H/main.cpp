#include <iostream>
#define ll long long
using namespace std;
ll price_game[100020];
ll jian_able[100020]={0};
ll day[100020000]={0};
int main() {
    ll start,income,num_game,jian;
    scanf("%lld %lld %lld %lld",&start,&income,&num_game,&jian);
    ll total_price=0;
    ll ma=0;
    if(jian==0){
        for (ll i = 1; i <= num_game; ++i) {
            ll tmp = 0;
            scanf("%lld",&tmp);
            total_price+=tmp;

        }
        ll d=1;
        if(start>=total_price){
            printf("1 morning");
            return 0;}
        start+=income;
        if(start>=total_price){
            printf("1 evening");
            return 0;}
        start-=income;
        ll cha=total_price-start;
        ll need_in = cha/income;
        if(cha%income==0){
            printf("%lld evening",need_in);
            return 0;
        } else{
            need_in++;
            printf("%lld evening",need_in);
            return 0;
        }

        return 0;
    }
    for (ll i = 1; i <= num_game; ++i) {
        ll tmp = 0;
        scanf("%lld",&tmp);
        total_price+=tmp;
//        price_game[i] = tmp;
        if(tmp>jian){
            ll tmp2 = tmp/jian;
            if(tmp%jian==0){
                tmp2--;
            }
            jian_able[i] = tmp2;
            if(ma<tmp2){
                ma = tmp2;
            }
        }
    }
    for (ll k =1; k <=num_game; ++k) {
       day[ jian_able[k]]++;
    }

    for (ll k = ma; k >=1 ; --k) {
        day[k]+=day[k+1];
    }

    ll j = 1;
    if(start>=total_price){printf("1 morning");
        return 0;}
    start+=income;
    if(start>=total_price){printf("1 evening");
        return 0;}

    while (true){

        total_price -= jian * day[j];
        if(start>=total_price){
            printf("%lld morning",j+1);
            return 0;
        }
        start+=income;
        if(start>=total_price){
            printf("%lld evening",j+1);
            return 0;
        }
        j++;
    }

    return 0;
}