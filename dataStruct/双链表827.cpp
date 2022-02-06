#include <iostream>
using namespace std;

const int N = 100010;

int n;
int e[N],l[N],r[N],idx;

void init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}
//在k右插入一点.
void add(int k,int x){
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void add_left(int k,int x){
    add(l[k],x);
}
//删除第k个点
void del(int k){
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

int main()
{
    init();
    scanf("%d", &n);
    for(int i = 0; i< n ; i++){
        char t ;
        cin >> t;
        if(t =='L'){
            int v;
            cin >> v;
            add(0,v);
        }else if(t == 'R'){
            int v;
            cin >> v;
            add(l[1],v);
        }else if(t == 'D'){
            int k;
            cin >> k;
            del(k+1);
        }else if(t == 'I'){
            char tt;
            cin >> tt;
            if(tt == 'L'){
                int k,v;
                cin >>k >>v;
                add_left(k+1,v);
            }else{
                int k,v;
                cin >>k >>v;
                add(k+1,v);
            }
        }
    }
    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    return 0;
}

