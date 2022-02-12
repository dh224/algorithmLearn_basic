#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

void is_Prime(int t){
    if(t == 1){ cout << "No" << endl;return;}
    if(t == 2){ cout << "Yes" << endl;return;}
    for(int i = 2; i <= t / i; i++){
        if(t % i == 0){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d",&t);
        is_Prime(t);
    }
    return 0;
}