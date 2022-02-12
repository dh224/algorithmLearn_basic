#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int stack[N];
int n;
int head = 0,tail = -1;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        string op;
        cin >> op;
        if(op == "push"){
            int v;
            cin >> v;
            stack[++tail] = v;
        }else if(op =="pop"){
            head++;
        }else if(op =="empty"){
            if(head <=tail ){
                cout <<"NO"<<endl;
            }else{
                cout << "YES" <<endl;
            }
        }else{
            cout << stack[head]<<endl;
        }
    }
    return 0;
}

