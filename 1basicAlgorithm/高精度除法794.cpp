#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

tuple<vector<int>,int> div(vector<int> A,int b){
    int t = 0 ;
    int r = 0;
    vector<int> ans;
    for(int i = A.size() - 1; i>= 0 ; i--){
        r = r * 10 + A[i];
        ans.push_back(r / b);
        r %= b;
    }
    reverse(ans.begin(),ans.end());
    while(ans.size() > 1 && ans.back() == 0){
        ans.pop_back();
    }
    return { ans,r};
}

int main()
{
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0 ; i--){
        A.push_back(a[i] - '0');
    }
    auto [arr,r] = div(A,b);
    for(int i = arr.size() - 1; i >= 0 ; i --){
        printf("%d",arr[i]);
    }
    cout << endl << r;
    return 0;
}
