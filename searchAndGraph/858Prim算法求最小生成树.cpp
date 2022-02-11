#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 501,INF = 0x3f3f3f3f;
int n,m;
int g[N][N];
int dist[N];
bool st[N];
int prim(){
    memset(dist, 0x3f, sizeof dist);
    
    int res = 0;
    for(int i = 0;i < n; i++){
        int pointer = -1;
        for(int j = 1;j <=n;j++){
            if(!st[j] && 
            (pointer == -1 || dist[pointer] > dist[j])){
                pointer = j; //找到没在集合中且距离最近的点
            }
        }
        if(i!=0 && dist[pointer] == INF){//图不联通
            return INF;
        }
        if(i != 0 ){//防止第一条就不连通，导致后面没循环.
            res+= dist[pointer];
        }
        for(int j = 1; j <= n ; j++){ //更新每一条边的距离
            dist[j] = min(dist[j],g[pointer][j]); // g[pointer][j]代表j到集合的距离，也即pointer->j边的距离
        }

        st[pointer] = true;
    }
    return res;
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f , sizeof g);
    for(int i = 0; i < m;i++){
        int x,y,z;
        scanf("%d%d%d", &x, &y,&z);
        g[x][y] = g[y][x] = min(g[x][y],z);
    }
    int ans = prim();
    if(ans > INF / 2) cout << "impossible"  << endl;
    else cout << ans << endl;
    return 0;
}