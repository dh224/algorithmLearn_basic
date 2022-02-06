#include <iostream>

using namespace std;
const int N = 100010;
int n;
int head,e[N],ne[N],idx;// idx存储当前操作的点

void init(){
    head =-1;
    idx =0;
}

void add_to_head(int v){
    ne[idx] = head;
    head = idx;
    e[idx] = v;
    idx++;
}
void add(int k,int v){
    ne[idx] = ne[k];
    ne[k] = idx;
    e[idx] = v;
    idx++;
}

void del(int k){
    ne[k] = ne[ne[k]];
    
}
int main()
{
    init();
    scanf("%d", &n);
    for(int i = 0; i< n ; i++){
        char t ;
        cin >> t;
        if(t =='H'){
            int v;
            cin >> v;
            add_to_head(v);
        }else if(t == 'D'){
            int k;
            cin >> k;
            if(!k) head = ne[head];
            else del(k-1);
        }else{
            int k,v;
            cin >>k>>v;
            add(k-1,v);
        }
    }
    for(int i = head; i != -1; i = ne[i]){
        printf("%d ",e[i]);
    }
    return 0;
}