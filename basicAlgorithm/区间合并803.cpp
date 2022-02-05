#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> segs;
void merge(vector<pair<int,int>> &segs){
    vector<pair<int,int>> res;
    sort(segs.begin(),segs.end());
    int st = -2e9,ed = -2e9;
    for(auto seg:segs){
        if(ed < seg.first){ // 完全无交集
            if(st != -2e9){ //规避初始的区间计数.
                res.push_back({st,ed}); // 此种情况下说明st ed组成的区间完全无交集，即一个新的独立区间
            }
            st = seg.first;
            ed = seg.second;
        }else{
            ed = max(ed,seg.second);
        }
    }
    if(st != -2e9) res.push_back({st,ed});//记得要添加最后一个区间.
    segs=res;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i< n;i++){
        int l,r;
        scanf("%d%d", &l, &r);
        segs.push_back({l,r});
    }
    merge(segs);
    cout <<segs.size()<<endl;
    return 0;
}
