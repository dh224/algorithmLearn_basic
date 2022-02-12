#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int p[N],s[N];

int n,m;

int find(int x){ //返回x所在集合的编号
    if(x !=p[x]){
        p[x] = find(p[x]); // 路径压缩优化
    }
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1;i<=n;i++){
        p[i] = i;
        s[i] = 1;
    }
    for(int i =0; i <m;i++){
        string op;
        int a,b;
        cin >> op ;
        if(op[0] == 'C'){
            cin >> a>>b;
            if(find(b)!= find(a)){//注意此处要先判断a、b是否已经在同一集合内。如果是，则不需要合并。
                s[find(b)] += s[find(a)];
                p[find(a)] = find(b);
            }

        }else if(op[1] == '1'){
            cin >> a>>b;
            if(find(a) == find(b)) cout << "Yes" <<endl;
            else cout << "No" << endl;
        }else{
            cin >> a;
            cout << s[find(a)] <<endl;
        }
    }
    return 0;
}