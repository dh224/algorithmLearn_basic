#include <iostream>

using namespace std;

const int N = 10000010;

int a[N],q[N]; //a存储输入的数列 q存储数列的下表

int n,k;
int main()
{
    scanf("%d%d", &n,&k);
    
    for(int i = 0;i <n;i++){
        scanf("%d", &a[i]);
    }
    
    int head = 0,tail = -1;
    for(int i=0;i<n;i++){
        //判断队头是否已经滑出窗口
        if(head <=tail && i - k + 1 > q[head]){
            head ++;
        }
        while(head <= tail && a[q[tail]] >= a[i]){
            tail--;
        }
         q[++tail] = i;
        if(i >=k-1){
            printf("%d ",a[q[head]]);
        }
       
    }
    printf("\n");
        head = 0,tail = -1;
        for(int i=0;i<n;i++){
            //判断队头是否已经滑出窗口
            if(head <=tail && i - k + 1 > q[head]){
                head ++;
            }
            while(head <= tail && a[q[tail]] <= a[i]){
                tail--;
            }
             q[++tail] = i;
            if(i >=k-1){
                printf("%d ",a[q[head]]);
            }
       
        }
    
    return 0;
}