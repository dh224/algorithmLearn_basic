#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100010 ;
int n;
int q[N],temp[N];
LL  ans;

LL merge_sort(int l,int r){
    if(l>=r) return 0;
    int mid = (l + r) >> 1;
    LL res = merge_sort(l,mid) + merge_sort(mid + 1,r);

    int k = 0,i = l,j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) temp[k++] = q[i++];
        else {
            temp[k++] = q[j++];
            res += mid - i + 1;
        }
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];
    for(int i=l,j = 0; i<= r;i++,j++){
        q[i] = temp[j];
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i= 0 ; i < n ; i++){
        scanf("%d",&q[i]);
    }
    ans = merge_sort(0,n-1);
    cout << ans <<endl;
    return 0;
}
