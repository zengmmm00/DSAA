#include <iostream>
using namespace std;
int n;
int m;

int main() {
    scanf("%d", &n);
    scanf("%d", &m);

    if(n > 3){
        printf("0");
    }else if(n == 0 || n ==1){
        if(m == 1){
            printf("0");
        } else{
            printf("1");
        }
    } else if(n == 2){
        if(m == 1 || m ==2){
            printf("0");
        } else{
            printf("2");
        }
    } else {
        long long result = 720;
        long long count = 719;
        while(count >= 1){
            result = ((result % m) * (count % m))%m;
            count--;
        }
        printf("%lld", result);
    }

    return 0;
}


//#include<cstdio>
//#define LL long long
//int main()
//{
//    LL n,p;
//    scanf("%lld%lld",&n,&p);
//    if(n==0)
//    {
//        printf("%lld\n",1%p);
//    }
//    else
//    {
//        LL sum=1;
//        for(LL i=1;i<=n;++i)
//        {
//            sum=sum%p*i%p;
//        }
//        printf("%lld\n",sum);
//    }
//
//    return 0;
//}