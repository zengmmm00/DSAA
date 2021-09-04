#include <iostream>
#include <vector>
using namespace std;
struct node{
    long long value=0;
    node * left;
    node * right;
};
node* address[150005];
long long queue[150005]={0};
int main() {
    long long T;
    scanf("%lld",&T);
    for (long long j = 0; j <= 150004; ++j) {
        node *p = new node;
        address[j] = p;
    }
    for (long long i = 0; i < T; ++i) {
        long long N;
        scanf("%lld",&N);
        if(N==1){
            long long a,b;
            scanf("%lld %lld",&a,&b);
            printf("Yes\n");
            continue;
        }
        long long root = (1+N)*N/2;
        for (long long j = 1; j <= N; ++j) {
            long long a,b;
            scanf("%lld %lld",&a,&b);
            root=root-a-b;
            address[j]->value = j;
            address[j]->left = address[a];
            address[j]->right = address[b];
        }
        long long front = 0,rear = 1;
        queue[0]=root;
        while(rear<N){
            if(address[queue[front]]->left->value==0||address[queue[front]]->left== nullptr)break;
            queue[rear++] = address[queue[front]]->left->value;
            if(address[queue[front]]->right->value==0||address[queue[front]]->right== nullptr)break;
            queue[rear++] = address[queue[front]]->right->value;
            front++;
        }
        if(rear==N)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}