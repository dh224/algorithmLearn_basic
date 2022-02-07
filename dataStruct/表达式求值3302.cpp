#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

const int N = 100010;
stack<int> num;
stack<char> op;

void eval(){
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top();op.pop();
    int x;
    if(c == '+'){
        x = a + b;
    }else if(c=='-'){
        x = a - b;
    }else if(c=='*'){
        x = a * b;
    }else{
        x = a / b;
    }
    num.push(x);
}

int main()
{
    unordered_map<int,char> pr{{'+',1},{'-',1},{'*',2},{'/',2}};
    string l;
    cin >> l;
    for(int i = 0; i<l.size();i++){
        auto c = l[i];
        if(isdigit(c)){
            int tempx = 0;
            int j;
            for( j= i;j < l.size() && isdigit(l[j]);j++){
                tempx= tempx*10 + l[j] - '0';
            }
            num.push(tempx);
            i = j-1;
        }else if(c == '('){
            op.push(c);
        }else if(c == ')'){
            while(op.top() != '('){
                eval();
            }
            op.pop();
        }else{
            while(op.size() && pr[op.top()] >= pr[c]) eval();
            op.push(c);
        }
    }
    while(op.size()) eval();
    cout << num.top() <<endl;
    return 0;
}

