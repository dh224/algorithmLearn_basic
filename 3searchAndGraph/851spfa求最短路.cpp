#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010,M = 100010 * 10;

int n,m,k;
int dist[N];
bool st[N];

int h[N];
int e[M],ne[M],w[M],idx;

void insert(int a,int b,int z){
    e[idx] = b;//记录新节点
    ne[idx] = h[a];//将新节点的后继指向当前节点的后继
    w[idx] = z;
    h[a] = idx++; //将对应起点的后继指向新创建的节点.
}

int spfa(){
    
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    dist[1] = 0;
    st[1] = true; //此处st用来判断当前节点是否已经在队列里了，如果在，则不需要存入.因为是没有意义的.
    q.push(1);//将第一个节点放入
    //对bf算法的改进：只有前驱节点变小了，后继才有可能变小。因此维护一个队列。当某节点的最短距离变小，将其加入队列。并在循环中判断所有后继。
    while(q.size()){
        int t= q.front();q.pop();
        st[t] = false ;
        for(int i = h[t]; i != -1 ; i = ne[i]){ //遍历最近的一个最短距离变小的点的所有的边
            int j = e[i]; //j e[i]存储的是当前边的终点.
            if(dist[j] > dist[t] + w[i]){ //如果到当前边的终点的最短距离大于从最近的一个最短距离变小的点+当前边的权重.
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0 ;i < m ; i++){
        int a,b,w;
        scanf("%d%d%d", &a, &b,&w);
        insert(a,b,w);
    }
    
    int ans = spfa();
    if(ans >= 0x3f3f3f3f / 2){
        cout << "impossible" << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}