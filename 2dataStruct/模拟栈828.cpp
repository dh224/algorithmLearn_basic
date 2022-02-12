#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int stack[N];
int n;
int head= -1;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        string op;
        cin >> op;
        if(op == "push"){
            int v;
            cin >> v;
            stack[++head] = v;
        }else if(op =="pop"){
            head--;
        }else if(op =="empty"){
            if(head == -1){
                cout << "YES"<<endl;
            }else{
                cout <<"NO"<<endl;
            }
        }else{
            cout << stack[head]<<endl;
        }
    }
    return 0;
}

