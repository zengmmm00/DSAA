#include <iostream>
using namespace std;
struct cell{
    int data;
    int counter;
    cell(){}
    cell(int d, int c):data(d), counter(c){}
};
cell queue[2000001];
int front = 0;
int rear =0;
int num =0;
void enQueue(cell item){
    queue[rear] = item;
    num ++;
    rear++;
}
void deQueueFront(){
    num--;
    front++;
}
void deQueueRear(){
    num--;
    rear--;
}

int main() {
    int m ;
    scanf("%d",&m);
    int n;
    int index =1;
    int ans;
    scanf("%d",&ans);
    cell c(ans, index);
    enQueue(c);
    while (index<m){
        index++;
        scanf("%d",&n);
        while (n > queue[rear-1].data && num !=0){
            deQueueRear();
        }
        cell tmp(n,index);
        enQueue(tmp);
    }
    ans = queue[front].data;
    while (scanf("%d", &n)&&n !=-1){
        index++;
        if(queue[front].counter +m== index){
            deQueueFront();
        }
        while (n > queue[rear-1].data&&num!=0){
            deQueueRear();
        }
        cell tmp(n,index);
        enQueue(tmp);
        ans = ans ^ queue[front].data;
    }

    printf("%d", ans);
    return 0;
}