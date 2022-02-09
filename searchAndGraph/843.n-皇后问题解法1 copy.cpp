#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~解法1
const int N = 19;
int n;
char g[N][N];
int row[N],col[N],dg[N],udg[N];

void dfs(int x, int y, int s){
    if(y == n) y=0,x ++;
    if(x == n){
        if(s == n){
            for(int i = 0;i < n;i++){
                cout << g[i]<<endl;
            }
            cout << endl;
        }
        return;
    }
    //不放皇后
    dfs(x,y+1,s);
    
    //放
    if(!row[x]&& !col[y] && !dg[x+y] && !udg[n + y - x]){
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x+y] = udg[n+ y - x] = true;
        dfs(x,y+1,s+1);
        row[x] = col[y] = dg[x+y] = udg[n+ y - x] = false;
        g[x][y] = '.';
    }
}


int main()
{
    cin >> n;
    for(int i = 0 ; i < n;i ++)
        for(int j = 0 ;j< n;j++)
            g[i][j] = '.';
    dfs(0,0,0);
    return 0;
}