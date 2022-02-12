#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 101;


int n,m;
int g[N][N];
int d[N][N];

queue<pair<int, int>> q;

//pair<int, int> q[N*N];

int bfs(){
    q.push({0,0});
    memset(d,-1,sizeof d);
    d[0][0] = 0;//初始化
    int dx[4] = {0, 1, 0, -1},dy[4] ={1, 0, -1, 0};
    //使用stl的queue
    while(q.size()>0){
        auto t = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int x = t.first +dx[i],y = t.second+ dy[i];
            if(x>=0 && x<n && y>=0 && y < m 
            && g[x][y] != 1 && d[x][y] == -1){
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x,y});//将当前点放入队列.
            }
        }
    }
    //自己实现队列
    // while(head <= tail){
    //     auto t = q[head++];
    //     for(int i = 0; i< 4;i++){
    //         int x = t.first +dx[i],y = t.second+ dy[i];
    //         if(x>=0 && x<n && y>=0 && y < m 
    //         && g[x][y] != 1 && d[x][y] == -1){
    //             d[x][y] = d[t.first][t.second] + 1;
    //             q[++tail] = {x,y};
    //         }
    //     }
    // }
    return d[n-1][m-1];
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    
    cout << bfs()<<endl;
    return 0;
}