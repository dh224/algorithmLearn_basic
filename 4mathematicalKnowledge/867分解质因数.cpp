#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

void divide_Prime(int x){
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0){ //此时i是质数，因为是从小到大的.
            int power = 0;
            while(x % i == 0){//此循环会进行到不能整除为止，此时记录的就是质因数的几次方。接下去判断是否还有别的质因数.
                x /= i;
                power++;
            }
            cout << i << " " << power << endl;
        }
    }
    //此时需要特判一种情况：剩余的x本身恰好就是一个质因数，因此导致循环结束。因此只要剩余的x大于1，则可以断定它是质因数，需要输出.
    if(x > 1) cout << x << " "<< 1 << endl;
    cout << endl;
}

int main()
{
    cin >> n;
    while(n--){
        int x;
        scanf("%d", &x);
        divide_Prime(x);
    }
    return 0;
}