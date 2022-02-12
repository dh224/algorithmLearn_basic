#include <iostream>
using namespace std;

int n,t;

int lowbit(int x){
    return x &(-x);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n ; i++){
        scanf("%d", &t);
        int res = 0;
        while(t){
            t -=lowbit(t); // 每次减去x的最后一位1
            res ++;
        }
        cout << res <<" ";
    }

    return 0;
}