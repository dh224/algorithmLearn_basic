#include <iostream>
#include <vector>

using namespace std;

vector<int> sub(vector<int> &a,vector<int> &b){
    vector<int> ans;
    int t = 0;
    for(int i = 0 ; i < a.size(); i++){
        t = a[i] - t;
        if(i <b.size()) t -=b[i];
        ans.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    while(ans.size() > 1 && ans.back() == 0){
        if(!ans[ans.size() - 1]) ans.pop_back(); 
    }
    return ans;
}

bool cmp(vector<int> &a,vector<int> &b){
    if(a.size() != b.size()) return a.size() > b.size();
    for(int i= a.size() - 1 ; i >= 0;i--){
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return true;
}

int main()
{
    string a,b;
    vector<int> A,B,C;
    bool flag = false;
    cin >> a >>b;
    for(int i= a.size() - 1; i >= 0; i--){
        A.push_back(a[i] - '0');
    }
    for(int i= b.size() - 1; i >= 0; i--){
        B.push_back(b[i] - '0');
    }
    if(cmp(A,B)){
        C= sub(A,B);
    }else{
        C = sub(B,A);
        flag = true;
    }
    if(flag){
        printf("-");
    }
    for(int i= C.size() - 1; i >= 0; i--){
        printf("%d",C[i]);
    }
    return 0;
}