#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        int res = a;
        for(int j = 2; j <= a / j; j++){
            if(a % j == 0){
                res = res / j * (j - 1);
                while(a % j == 0) a /= j;
            }
        }
        if(a > 1) res = res / a * (a - 1);
        cout << res << endl;
    }
    return 0;
}
