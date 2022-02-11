#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 501,M = 10010;

int n,m,k;
int dist[N],backup[N];

struct Edge{
    int a,b,w;
}edges[M];

int bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < k ;i++){
        memcpy(backup,dist,sizeof dist);//防止出现串联，即遍历所有边时，被当前修改的长度影响了后面的值。
        for(int j = 0; j < m;j++){
            int a = edges[j].a,b = edges[j].b,w = edges[j].w;
            dist[b] = min(dist[b],backup[a] + w);//此处用尚未更新的距离，避免串联。防止出现超过k的情况（因为这个for循环不考虑k).
        }
    }
    return dist[n]; //避免负权边相加小于无穷大.
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0 ;i < m ; i++){
        int a,b,w;
        scanf("%d%d%d", &a, &b,&w);
        edges[i] = {a,b,w};
    }
    
    int ans = bellman_ford();
    if(ans >= 0x3f3f3f3f / 2){
        cout << "impossible" << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}