#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
int n,m;
int v[N],w[N];
int f[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <=n; i++){
        cin >> v[i] >> w[i];
    }
    //由于f[0][m],m为任意数字均为0，又变量初始化即为0，因此不用写了,从1开始
    for(int i =1; i <= n ; i++){
        for(int j = m; j >= v[i]; j--){
                f[j] = max(f[j],f[j - v[i]] + w[i]);
            
        }
    }
    cout << f[m] << endl;
    
    return 0;
}