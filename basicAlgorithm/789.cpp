#include <iostream>
const int N = 100010;
using namespace std;

int n,q;

int arr[N];

int main()
{
    scanf("%d %d",&n,&q);
    for(int i = 0; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i <q;i++){
        int qes;
        scanf("%d", &qes);
        int l = 0,r= n-1;
        while(l < r){
            int mid = l + r>>1;
            if(arr[mid] >= qes){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if(arr[l] != qes) cout << "-1 -1" << endl;
        else {
            cout << l << " ";
            l = 0,r= n-1;
            while(l < r){
                int mid = l + r + 1 >>1;
                if(arr[mid] <= qes){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            cout << l << endl;
        }
    }
    return 0;
}