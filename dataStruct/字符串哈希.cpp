#include <iostream>

using namespace std;

const int N =  100010,P = 131; //or 1331

int n,m;
char str[N];
unsigned long long h[N],p[N];

unsigned long long get(int l,int r){
    return h[r] - h[l - 1] * p[r - l + 1]; // r- l + 1 为l 至 r的距离。具体数值在下方被预处理
}

int main()
{
    scanf("%d%d%s", &n, &m,str+1);
    int t = 0;
    p[t] = 1;
    while(t++<=n){
        p[t] = p[t - 1] * P; //预处理每一位的P  P^1 P^2……
        h[t] = h[t - 1] * P + str[t];
    }
    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d", &l1,&r1,&l2,&r2);
        if(get(l1,r1) == get(l2,r2)) cout << "Yes" <<endl;
        else cout << "No" << endl;
    }
    return 0;
}