#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res =(long long)res * a % p;
        k >>= 1;
        a = (long long)a * a % p;
    }
    return res;
}


int main()
{
    cin >> n;
    while(n--){
        int a,p;
        scanf("%d%d", &a,&p);
        int res = qmi(a,p-2 ,p);
        if(a % p){
            printf("%d\n",res);
        }else{
            printf("impossible\n");
        }

    }
}
