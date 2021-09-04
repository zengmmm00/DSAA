#include <iostream>
#define ll long long
using namespace std;

struct node{
    ll note;
    ll index;
    node *next;
    node *last;
};

int main() {
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        ll n = 0;
        scanf("%lld", &n);
        ll m = 0;
        scanf("%lld",&m);

        if(n == 1){
            ll a = 0;

            scanf("%lld",&a);
            printf("1\n");
        } else{
            //create list
            node *head = new node;
            node *p = head;
            ll b = 0;
            scanf("%lld",&b);
            head->note = b;
            head->index = 1;
            for (int j = 0; j < n-1; ++j) {
                node *tmp = new node;
                ll c = 0;
                scanf("%lld",&c);
                tmp->note = c;
                tmp->index = 2 + j;
                p->next = tmp;
                tmp->last = p;
                p = p->next;
            }
            p->next = head;
            head->last = p;
            //delete
            ll count = m;
            for (int j = n; j > 1; j--) {
                ll a = count % j;
                if(a != 0){
                    if(a > j / 2){
                        for (int i = 0; i < j - a; ++i) {
                            p = p->last;
                        }
                    } else{
                        for (int i = 0; i < a; ++i) {
                            p = p->next;
                        }
                    }
                }
                count = p->note;
                node *tmp = p;
                p = p->next;
                p->last = tmp->last;
                p = p->last;
                p->next = tmp->next;
                delete tmp;
            }

            //output
            printf("%lld\n", p->index);
        }
    }
    return 0;
}