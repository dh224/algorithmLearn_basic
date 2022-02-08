#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
const int N = 100010;
int h[N];
int _size;

void down(int u){
    int t= u ;
    if(u * 2 <= _size && h[u*2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= _size && h[u * 2 + 1] < h[t]) t =u * 2 + 1;
    if( u != t){ // 说明最小值在左右子节点之间
        swap(h[t],h[u]);
        down(t);
    }
    
}

void up(int u){
    int t = u;
    while(u / 2 && h[u / 2] > h[u]){
        swap(h[u],h[u/2]);
        u /= 2;
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n ; i++){
        int t;
        cin >> t;
        h[i] = t;
    }
    _size = n;
    
    for(int i = n / 2; i ;i--) down(i);  //O(n)的建堆方式。正常的方法，即每次往堆中插入x个数字，需要O(nlogn)。此种方法只需要on。用数列可证明.
    
    while(m--){
        cout << h[1] << " ";
        h[1] = h[_size--];
        down(1);
    }
    
    return 0;
}