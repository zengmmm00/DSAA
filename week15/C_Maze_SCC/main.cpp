#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> graph[200002];
vector<int> r_graph[200002];

int color[200002] = {0};//white = 0; yellow = 1; red = -1;
int r_color[200002] = {0};//white = 0; yellow = 1; red = -1;

stack<int> LR;
stack<int> s1;
stack<int> s2;

bool dfs1(int n){
    r_color[1] = 1;
    s1.push(1);
    while (LR.size() < n){
        if(s1.empty()){
            return false;
        }
        int root = s1.top();
        bool found = false;
        for (int i = 0; i < r_graph[root].size(); ++i) {
            if(r_color[r_graph[root][i]] == 0){
                s1.push(r_graph[root][i]);
                r_color[r_graph[root][i]] = 1;
                found = true;
                break;
            }
        }
        if(!found){
            r_color[root] = -1;
            s1.pop();
            LR.push(root);
        }
    }
    return true;
}

void dfs2(){
    color[LR.top()] = 1;
    s2.push(LR.top());
    while (!s2.empty()){
        int root = s2.top();
        bool found = false;
        for (int i = 0; i < graph[root].size(); ++i) {
            if(color[graph[root][i]] == 0){
                s2.push(graph[root][i]);
                color[graph[root][i]] = 1;
                found = true;
                break;
            }
        }
        if(!found){
            color[root] = -1;
            s2.pop();
            LR.pop();
        }
    }
    if(LR.empty()){
        printf("Bravo");
    } else{
        printf("ovarB");
    }
}

void input(int m){
    for (int i = 0; i < m; ++i) {
      int u,v;
      scanf("%d %d",&u,&v);
      graph[u].push_back(v);
      r_graph[v].push_back(u);
    }
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    input(m);
    if (dfs1(n)){
        dfs2();
    } else{
        printf("ovarB");
    }

    return 0;
}