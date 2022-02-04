#include <iostream>
using namespace std;

const int N = 1010;

int a[N][N],b[N][N];
int n,m,q;


void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main()
{
    scanf("%d%d%d", &n, &m,&q);
    for(int i = 1; i <= n;i++){
        for(int j = 1;j<= m;j++){
            scanf("%d", &a[i][j]);
            insert(i, j, i, j, a[i][j]);//构造差分矩阵
        }
    }
    while(q--){
        int x1,y1,x2,y2,c;
        scanf("%d%d%d%d%d", &x1, &y1,&x2,&y2,&c);
        insert(x1, y1, x2, y2, c); //利用差分矩阵进行快速计算
    }
    for(int i = 1; i <= n;i++){
        for(int j = 1;j<= m;j++){
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            printf("%d ",b[i][j]);
        }
        puts("");
    }
    return 0;
}