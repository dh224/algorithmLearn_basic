#include <iostream>

const int N = 100010;
int n,m;

int a[N],b[N];

void insert(int l,int r,int c){
    b[l] += c;
    b[r+1] -= c;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i= 1; i <= n ;i++){
        scanf("%d", &a[i]);
        insert(i,i,a[i]); //此处巧妙地构造了差分数组b
    }
    while (m -- ){
        int l,r,c;
        scanf("%d%d%d", &l, &r,&c);
        insert(l,r,c);
    }
    
    for(int i = 1; i<= n ; i++){
        b[i] += b[i-1]; //求前缀和。由于b是差分数组，因此差分数组的前缀和即为原数组。
        printf("%d ",b[i]);
    }
    
    return 0;
}