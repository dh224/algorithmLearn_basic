#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 24500,M = 2001;
int f[N];
int v[N];
int w[N];
int s[N];

int main()
{
    int n,m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n ; i++){
        int a,b,s;
        cin >> a >> b >> s;
        int k = 1;
        while(k <= s){
            cnt ++ ;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s > 0){
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    n = cnt;
    for(int i = 1; i <= n; i ++){
        for(int j =m; j >= v[i] ;j--){
            f[j] = max(f[j],f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}