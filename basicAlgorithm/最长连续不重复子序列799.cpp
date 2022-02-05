#include <iostream>
using namespace std;

const int N = 100010;
int q[N],s[N];
int n;

int main()
{
    scanf("%d", &n);
    int res = 0;
    for(int i = 0 ; i < n ; i++) scanf("%d", &q[i]);
    for(int i = 0,j = 0 ; i < n ; i++){
        s[q[i]]++;
        while(s[q[i]] > 1){
            s[q[j]]--;
            j++;
        } 
        res = max(res,i - j + 1);
    }
    cout << res << endl;
    return 0;
}