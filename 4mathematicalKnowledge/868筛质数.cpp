#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000010;
int n ;
int primes[N],cnt;
bool st[N];


void get_Prime_ejypt(int x){
    for(int i = 2; i <= x; i++){
        if(!st[i]){
            primes[cnt++] = i;
        }
        for(int j = 0; primes[j] <= x / i; j ++){
            st[primes[j] * i] = true;
            if(i%primes[j] == 0 ) break;
        }
    }
    
}

int main()
{
    cin >> n;
    get_Prime_ejypt(n);
    cout << cnt << endl;
    return 0;
}