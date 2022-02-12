#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int gcd(int x,int y){
    if(x % y == 0)return y;
    return gcd(y,x % y);
}
int main() {
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
    return 0;
}