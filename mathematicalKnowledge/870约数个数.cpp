#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
vector<pair<int ,int>> q;
void divide_Prime(int x){
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0){ //此时i是质数，因为是从小到大的.
            int power = 0;
            while(x % i == 0){//此循环会进行到不能整除为止，此时记录的就是质因数的几次方。接下去判断是否还有别的质因数.
                x /= i;
                power++;
            }
            q.push_back({i,power});
        }
    }
    
}

int main()
{
    cin >> n;
    while(n--){
        int x;
        scanf("%d", &x);
        divide_Prime(x);
    }
    int ans = 1;
    for(auto &i : q){
        ans *= (i.second + 1);
    }
    cout << ans %(1000000007) <<endl;
    return 0;
}