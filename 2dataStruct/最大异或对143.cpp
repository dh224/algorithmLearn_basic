#include <iostream>

using namespace std;

const int N = 100010;
const int M = N * 31;
int son[M][2],idx;

int n;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i -- )
    {
        int &s = son[p][x >> i & 1];
        if (!s) s = ++ idx;
        p = s;
    }
}
int query(int t){
    int p = 0,res = 0;
    for(int i = 30;i >= 0;i--){
        int u = t >> i & 1;
        if(son[p][!u]){
            p = son[p][!u];
            res += 1 << i;
        }else{
            p = son[p][u];
        }
    }
    return res;
}

int main()
{
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n;i++){
        int t;
        cin >> t;
        insert(t);
        ans = max(ans,query(t));
    }
    cout << ans <<endl;
    return 0;
}