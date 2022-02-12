#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010,M = N * 10;
int n,m;

int h[N],e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void insert(int x,int y,int z){
    e[idx] = y;
    ne[idx] = h[x];
    w[idx] = z;
    h[x] = idx++;
}

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    priority_queue<pair<int ,int>,vector<pair<int ,int>>,greater<pair<int ,int>>> heap;
    heap.push({0,1});
    
    while(heap.size()){
        auto t = heap.top();heap.pop();
        int index = t.second,distance = t.first;
        if(st[index]) continue; //说明此点之前已经算过了.

        for(int i = h[index];i != - 1; i = ne[i]){
            int j = e[i];
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                heap.push({dist[j],j});
                st[index] = true;
            }
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
    memset(h, -1, sizeof h);
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1;j <= n; j++){
    //         if(i == j) g[i][j] = 0;
    //         else g[i][j] = INF;
    //     }
    // }
    for(int i = 0 ; i < m;i++){
        int x,y,z;
        scanf("%d%d%d", &x, &y,&z);
        insert(x,y,z);
    }
    cout << dijkstra() << endl;
    return 0;
}