#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n ;
const int N = 100003;

int h[N];
int e[N],ne[N],idx;

void insert(int x){
    int k = (x % N + N) % N; //在cpp中，负数取模仍为负数，因此加N可保证其一定为正.
        e[idx] = x;
        ne[idx] = h[k];
        h[k] = idx++;
}

bool find(int x){
    int k = (x % N + N) % N;
    for(int i = h[k];i != - 1;i=ne[i]){
        if(e[i] == x){
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0;i < n ; i++){
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I'){
            insert(x);
        }else{
            if(find(x)) cout << "Yes" <<endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}