#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int stack[N];
int n;
int head = 0;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        int x;
        cin >>x;
        while(head && stack[head] >= x){
            head--;
        }
        if(head){
            cout <<stack[head]<<" ";
        }else{
            cout << -1 <<" ";
        }
        stack[++head] = x;
    }
    return 0;
}

