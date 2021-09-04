#include <iostream>

using namespace std;
int n,m;
int start;
int find_same(string possible[],int count,string sub){
    int same=0;
    for (int i = 0; i < count; ++i) {
        if(sub==possible[i].substr(start,m)){
            same++;
        }
    }
    return same;
}

int main() {
    scanf("%d %d",&n,&m);
    string possible[n-m+1];
    for (int i = 0; i < n-m+1; ++i) {
        char tmp[n+1];
        scanf("%s",tmp);
        possible[i]=tmp;
    }
    string sub="";
    string ans="";
    int count =n-m+1;
    for (int i = 0; i < n-m+1; i+=m) {
        start = i;

        for (int j = 0; j < n-m+1; ++j) {
            sub = possible[j].substr(start,m);
            int same = find_same(possible, count,sub);
            if(same>=m){
                ans+= sub;
                break;
            }
        }

    }
    if(n%m!=0){
        start=(n/m)*m;
        int mm=n-start;
        for (int j = 0; j < n-m+1; ++j) {
            sub = possible[j].substr(start,mm);
            int same = find_same(possible, count,sub);
            if(same>=m){
                ans+= sub;
                break;
            }
        }
    }
    printf("%s",ans.c_str());
    return 0;
}