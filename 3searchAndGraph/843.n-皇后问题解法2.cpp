#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 19;
int n;
char g[N][N];
int row[N],dg[N],udg[N];

void dfs(int u){
    if(u == n){
        for(int i = 0;i < n ;i++){
            cout << g[i] <<endl;
        }
        cout << endl;
        return;
    }
    //此处u是列.相当于按列进行递归。与视频中的相反.不过无所谓，因为棋盘不分上下左右.
    for(int i = 0 ; i < n ; i++){
        if(!row[i] && !dg[i + u] && !udg[u - i + n]){
            g[i][u] = 'Q';
            row[i] = dg[i+u] = udg[u - i + n] = true;
            dfs(u + 1);
            row[i] = dg[i+u] = udg[u - i + n] = false;
            g[i][u] = '.';
        }
    }
}


int main()
{
    cin >> n;
    for(int i = 0 ; i < n;i ++)
        for(int j = 0 ;j< n;j++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}