#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100010;
int h[N],e[N],ne[N],idx;
int n,m;
int q[N],d[N];//q表示队列,d表示点的入度

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool topsort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
     if(!d[i]) 
     q[++tt]=i;//将入度为零的点入队
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            d[j]--;//删除点t指向点j的边
            if(d[j]==0)//如果点j的入度为零了,就将点j入队
            q[++tt]=j;
        }
    }
    return tt==n-1;
    //表示如果n个点都入队了话,那么该图为拓扑图,返回true,否则返回false
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof(h));//如果程序时间溢出，就是没有加上这一句
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);//因为是a指向b,所以b点的入度要加1
        d[b]++;
    }
    if(topsort()) 
    {
        for(int i=0;i<n;i++)
        printf("%d ",q[i]);
        //经上方循环可以发现队列中的点的次序就是拓扑序列
        //注:拓扑序列的答案并不唯一,可以从解析中找到解释
        puts("");
    }
    else
    puts("-1");

    return 0;
}
