#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int p[N];

int n,m;

int find(int x){ //返回x所在集合的编号
    if(x !=p[x]) p[x] = find(p[x]); // 路径压缩优化
    return p[x];
}

int find_NR(int x){
    while(p[x] != x){
        p[x] = p[p[x]];
    }
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1;i<=n;i++){
        p[i] = i;
    }
    for(int i =0; i <m;i++){
        char op;
        int a,b;
        cin >> op >> a >>b;
        if(op == 'M'){
            p[find(a)] = find(b);
        }else {
            if(find(a) == find(b)) cout << "Yes" <<endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}