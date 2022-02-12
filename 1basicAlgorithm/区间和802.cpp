#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> alls;
vector<pair<int,int>> add,query;


const int N = 300010;

int a[N],s[N];
int n,m;

int find(int x){
    int l = 0,r = alls.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main()
{
    scanf("%d %d", &n,&m);
    for(int i = 0;i < n;i++){
        int t,c;
        scanf("%d %d", &t,&c);
        add.push_back({t,c});
        alls.push_back(t);
    }

    for(int i = 0;i < m;i++){
        int l,r;
        scanf("%d %d", &l,&r);
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    //处理插入
    for(auto item : add){
        int x = find(item.first);
        a[x] += item.second;
    }
    //算前缀和
    for(int i = 1; i <= alls.size();i++){
        s[i] += s[i-1] + a[i];
    }
    //处理询问
    for(auto item:query){
        int l = find(item.first),r = find(item.second);
        cout <<s[r] - s[l-1]<<endl;
    }
    
    return 0;
}