#include <iostream>
#define ll long long
using namespace std;
struct node{
    double coef;
    double expo;
    node *next;
};

void insertNode(ll n, node*head1){
    node *p = head1;
    for (ll j = 0; j < n+1; ++j) {

        if(j == n){
            p->next = nullptr;
        } else{
            double input = 0;
            scanf("%lf", &input);
            p->coef = input;
            scanf("%lf", &input);
            p->expo = input;
            node *tmp = new node;
            p->next = tmp;
            p = p->next;
        }
    }

}
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        ll n= 0;
        scanf("%lld", &n);
        node *head1 = new node;
        insertNode(n,head1);
        ll m= 0;
        scanf("%lld", &m);
        node *head2 = new node;
        insertNode(m,head2);
        //find
        ll count = 0 ;
        scanf("%lld", &count);

        node *p1 = head1;
        node *p2 = head2;
        for (int j = 0; j < count; ++j) {
            ll k = 0;
            scanf("%lld", &k);
            double a = 0;
            double b = 0;
            while(k > p1->expo && p1->next != nullptr){
                p1 =p1->next;
            }
            //k <= p1
            if(k == p1->expo){
                a = p1->coef;
            }

            while (k > p2->expo&&p2->next != nullptr){
                p2 = p2->next;
            }
            if(k == p2->expo){
                b = p2->coef;
            }
            printf("%g ", a + b);
        }

    }
    return 0;
}