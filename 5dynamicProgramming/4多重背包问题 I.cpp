#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 101;
int f[N][N];
int v[N];
int w[N];
int s[N];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n ; i++){
        cin >> v[i] >> w[i] >> s[i];

    }
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= m ;j++){
            for(int k = 0; k <= s[i] && v[i] * k <= j ; k++){
                f[i][j] = max(f[i][j],f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}