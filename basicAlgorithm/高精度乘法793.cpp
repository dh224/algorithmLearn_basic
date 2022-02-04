#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> A,int b){
    int t = 0 ;
    vector<int> ans;
    for(int i = 0;i < A.size() | t; i++){
        if(i < A.size()) t += A[i] * b;
        ans.push_back(t % 10);
        t  /= 10;
    }
    while(ans.size() > 1 && ans.back() == 0){
        ans.pop_back();
    }
    return ans;
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
    auto C = mul(A,b);
    for(int i = C.size() - 1; i >= 0 ; i --){
        printf("%d",C[i]);
    }
    return 0;
}