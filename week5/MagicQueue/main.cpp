#include <iostream>
#include<ctime>

#include <stdio.h>
using namespace std;
int queue[20000001];
int front = 0;
int rear = 0;
void enQueue(int item){
    queue[rear] = item;
    rear++;
}
void deQueue(){
   if(front < rear){
       front++;
   }
}
int main(){

    time_t begin,end;
    double ret;
    begin=clock();

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char c = '0';
        scanf("%c", &c);
        scanf("%c", &c);
        if(c == 'E'){
            int x;
            scanf(" %d", &x);
            enQueue(x);

        } else if (c == 'D'){
            deQueue();
        } else{
            if(front == rear){
                printf("\n");
            }else{
                printf("%d\n", queue[front]);
            }
        }
    }
    if(front != rear){
        for (int i = front; i < rear; ++i) {
            printf("%d ", queue[i]);
        }
    } else{
        printf("");
    }

    end=clock();
    ret=double(end-begin)/CLOCKS_PER_SEC;
    cout<<"runtime:   "<<ret<<endl;

    return 0;
}