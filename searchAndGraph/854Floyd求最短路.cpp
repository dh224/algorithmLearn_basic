#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 210,INF = 1e9;

int n,m,k;
int d[N][N]; //邻接矩阵

void floyd(){
    for(int k = 1; k <= n ;k++){
        for(int i = 1; i <= n;i++){
            for(int j = 1;j <= n;j++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    
    for(int i =1; i <=n;i++){
        for(int j = 1; j <= n;j++){
            if(i == j){
                d[i][j] = 0;
            }else{
                d[i][j] = INF;
            }
        }
    }
    for(int i = 0; i < m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        d[x][y] = min(d[x][y],z);//只保留最小边.
    }
    floyd();
    while(k--){
        int a,b;
        scanf("%d%d",&a,&b);
        int t = d[a][b] ; 
        if(t >= INF / 2){
            printf("impossible\n");
        }else printf("%d\n",t);
        
    }
    return 0;
}