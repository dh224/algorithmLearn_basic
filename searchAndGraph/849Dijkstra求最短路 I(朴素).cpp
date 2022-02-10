#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int n,m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 0;i < n ; i++){
        int t = -1;
        for(int j = 1; j <= n;j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j])){
                t = j; //如果当前的点不是已经固定的值且t的距离比j的距离要大，则更新t
            }
        }
        st[t] = true;
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j],dist[t] + g[t][j]);
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else{
        return dist[n];
    }
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1;j <= n; j++){
    //         if(i == j) g[i][j] = 0;
    //         else g[i][j] = INF;
    //     }
    // }
    for(int i = 0 ; i < m;i++){
        int x,y,z;
        scanf("%d%d%d", &x, &y,&z);
        g[x][y] = min(g[x][y],z); //如有重边，保留最短的。
        //发现代码逻辑会直接无视自成环。因为默认c不可能小于0.
    }
    cout << dijkstra() << endl;
    return 0;
}