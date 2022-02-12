#include <cstring>
#include <iostream>

using namespace std;
const int N = 200003,null = 0x3f3f3f3f;

int h[N];

int find(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) {
        t++;
        if (t == N) {
            t = 0;
        }
    }
    return t;  //如果这个位置是空的, 则返回的是他应该存储的位置
}
int n;
int main()
{
    cin >> n;
    memset(h, 0x3f, sizeof h);
    for(int i = 0;i < n ; i++){
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        int k = find(x);
        if(*op == 'I'){
            h[k] = x; //这里是k应该存在的位置或者是x的位置
        }else{
            if(h[k] != null){
                cout << "Yes" <<endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}