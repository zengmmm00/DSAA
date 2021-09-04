#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
struct node{
    vector<int> vec;
    int ru=0;
};
node*arr[500010];
priority_queue<int> q;
stack<int> ans;

void bfs(){
    while(!q.empty()){
        int noRu = q.top();
        q.pop();
        ans.push(noRu);
        for (int j = 0; j < arr[noRu]->vec.size(); ++j) {
            int son = arr[noRu]->vec[j];
            arr[son]->ru--;
            if(arr[son]->ru==0){
                q.push(son);
            }
        }
    }
    while (!ans.empty()){
        printf("%d ",ans.top());
        ans.pop();
    }
    printf("\n");
}

void in(int m){
    for (int j = 0; j < m; ++j) {
        int qian,hou;
        scanf("%d %d",&qian,&hou);
        arr[hou]->vec.push_back(qian);
        arr[qian]->ru++;
    }
}

void findNoRu(int n){
    for (int j = 1; j <= n; ++j) {
        if(arr[j]->ru==0){
            q.push(j);
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        int n,m;
        scanf("%d %d",&n,&m);
        for (int k = 1; k <= n; ++k) {
            node*tmp=new node;
            arr[k]=tmp;
        }
        in(m);
        findNoRu(n);
        bfs();
        for (int j = 1; j <= n; ++j) {
            delete arr[j];
            arr[j]=NULL;
        }
    }

    return 0;
}