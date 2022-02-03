#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &a,vector<int> &b){
    vector<int> ans;
    
    int t = 0;
    for(int i= 0; i < a.size() ||i < b.size() ;i++){
        if(i < a.size()) t+=a[i];
        if(i < b.size()) t+=b[i];
        //此时t为 进位+a的值+b的值
        ans.push_back(t%10);//存个位数
        t /=10; //判断是否存在进位
    }
    if(t!=0) ans.push_back(1);
    return ans;
}

int main()
{
    string a,b;
    vector<int> A,B;
    cin >> a >>b;
    for(int i= a.size() - 1; i >= 0; i--){
        A.push_back(a[i] - '0');
    }
    for(int i= b.size() - 1; i >= 0; i--){
        B.push_back(b[i] - '0');
    }
    
    auto C = add(A,B);
    for(int i= C.size() - 1; i >= 0; i--){
        printf("%d",C[i]);
    }
    return 0;
}