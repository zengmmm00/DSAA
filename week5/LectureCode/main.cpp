#include <iostream>
using namespace std;
//int n = 0;
//int stack[n];
int top = -1;
//int maxSize = n;
void push(int item, int stack[], int n){
	if(top == n - 1){//attention -1
        //stack is full
	}else{
		top++;
		stack[top] = item;
	}
}
int pop(int stack[]){
	if(top == -1){
        return 0;
	}else{
		top--;
        return stack[top+1];
	}

}
//int postfixCalculator(int stack[], string str){
//    for (int i = 0; i < str.length(); ++i) {
//        if()
//    }
//}
int rear = 0;
int front = 0;
int count = 0;
void enQueue(int queue[], int item, int n){
//    if(rear < n){
//        queue[rear] = item;
//        rear++;
//    } else{
//        //rear = n
//        //queue is full
//
//    }
    if(count < n){
        if(rear == n){
            rear = 0;
        }
        queue[rear] = item;
        rear++;
        count++;
    } else{
        //queue is full
    }
}
void deQueue(int queue[], int n){
//    if(front < rear){
//        front++;
//    } else{
//        //queue is empty
//    }
    if(count != 0){
        if(front == n){
            front = 0;
        }
        front++;
        count--;
    } else{
        //queue is empty
    }
}
int main() {
    int stack[3];
    int n = 3;
    push(1,stack,n);
    cout << stack[0];
    string str = "fe";
    cout << str[0];

    return 0;
}