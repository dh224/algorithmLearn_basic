#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
const int N = 100010,M = N * 2;

int h[N],e[M],ne[M],idx;
int st[N];
int ans = N;
void insert(int a,int b)  // 插入字符串
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//返回以u为根的子树的大小
int dfs(int u){
    st[u] = true;
    int sum = 1,res = 0;
    for(int i = h[u];i!=-1;i = ne[i]){
        int j = e[i];
        if(!st[j]){
            int s =dfs(j);
            res = max(res,s);
            sum += s;
        }
    }
    res = max(res,n - sum);
    ans = min(ans,res);
    return sum;
}

int main()
{
    memset(h,-1,sizeof h);  
    cin >> n;
    for(int i = 0;i < n; i++){
        int ta,tb;
        cin >> ta >>tb;
        insert(ta,tb);
        insert(tb,ta);
    }
    dfs(1);
    cout << ans <<endl;
    return 0;
}