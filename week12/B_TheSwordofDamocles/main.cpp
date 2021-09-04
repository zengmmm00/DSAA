#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct monster{
    int n;
    int m;
    int distance;
    vector<int>vec;
    int color;//yellow = 1; red = -1;
};

//monster address[1003];
int queue[1003];
int front=0,rear=0;
void enQueue(int u){
    queue[rear] = u;
    rear++;
}
void deQueue(){
    front++;
}
bool bfs(monster address[],int k){
    enQueue(1001);
    address[1001].color=1;
    while(front!=rear) {
        monster* start = &address[queue[front]];
        deQueue();
        for (int i = 0; i < start->vec.size(); ++i) {
            if(start->vec[i]==1002){
                return true;
            }
            if(address[start->vec[i]].color==0){
                enQueue(start->vec[i]);
                address[start->vec[i]].color=1;
            }
        }
        start->color=-1;
    }
    return false;
}
int main() {
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        front=0,rear=0;
        monster address[1003];
//        address[1001].color=0;address[1002].color=0;
        int N,M,K;
        scanf("%d %d %d",&N,&M,&K);
        for (int j = 0; j < K; ++j) {
            address[j].color=0;
            scanf("%d %d %d",&address[j].n,&address[j].m,&address[j].distance);
            if(address[j].m - address[j].distance<=0
                || address[j].n + address[j].distance >= N)
            {
                address[j].vec.push_back(1001);
                address[1001].vec.push_back(j);
            }
            if(address[j].n<=address[j].distance
                || address[j].m+address[j].distance>=M)
            {
                address[j].vec.push_back(1002);
                address[1002].vec.push_back(j);
            }
        }
        for (int j = 0; j < K; ++j) {
            for (int k = j+1; k < K; ++k) {
                int areaSq = pow(address[j].n-address[k].n,2) + pow(address[j].m-address[k].m,2);
                if(sqrt(areaSq)<=address[j].distance+address[k].distance){
                    address[j].vec.push_back(k);
                    address[k].vec.push_back(j);
                }
            }
        }

//        printf("%d %d\n",address[100])
        if(!bfs(address,K))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}