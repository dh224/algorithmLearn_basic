#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n;

vector<int> get_Divisors(int x){
    vector<int> res;
    for(int i = 1; i <= x / i; i++){
        if(x % i == 0){
            res.emplace_back(i);
            if(i != x / i) res.emplace_back(x / i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d",&t);
        vector<int> res = get_Divisors(t);
        for(auto& i : res){
            cout << i <<" ";
        }
        cout << endl;
    }
    return 0;
}