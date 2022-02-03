#include <iostream>
#include<iomanip>
using namespace std;

double n;

double q(double i){
    return i*i*i;
}

int main()
{
    cin >> n;
    double l = -10000;
    double r = 10000;
    while(r - l > 1e-8){
       double mid = (l+r) / 2.0 ;
       if(q(mid) >= n){
           r = mid;
       }else{
           l = mid;
       }
    }
    cout <<fixed << setprecision(6)<<l <<endl;
    return 0;
}