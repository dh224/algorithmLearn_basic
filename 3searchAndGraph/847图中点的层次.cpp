#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;


const int N = 100010;
int h[N],e[N],ne[N],idx;
int d[N];
int n,m;
queue<int> q;

void insert(int a,int b)  // 插入字符串
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void bfs(){
    q.push(1);
    d[1] = 0;
    
    while(q.size() > 0){
        auto t = q.front();q.pop();
        for(int i = h[t];i != - 1; i =ne[i]){
            int j = e[i];
            if(d[j] == - 1){
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);
    for(int i = 0; i < m;i++){
        int ta,tb;
        cin >> ta >>tb;
        insert(ta,tb);
    }
    bfs();
    cout << d[n] <<endl;
    return 0;
    
}