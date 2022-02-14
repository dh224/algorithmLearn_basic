#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 1000010;
int primes[N],cnt;
bool st[N];
int n;
int phi[N];

long long get_eulers(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!st[i]){
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0;primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j] ;
                break; //保证每个数只会被他的最小质因数筛掉，因此o(n);
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
    
    long long res = 0;
    for(int i = 1; i <= n ; i++) res+=phi[i];
    return res;
}

int main()
{
    cin >> n;
    cout << get_eulers(n) << endl;
    return 0;
}