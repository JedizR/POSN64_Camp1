#include <bits/stdc++.h>

using namespace std;
int u[1010][1010],d[1010][1010],l[1010][1010],r[1010][1010];
char a[1010][1010];
int main()
{
    int q,rr,c,i,j,ans=-1;
    scanf("%d",&q);
    while(q--)
    {
        ans=-1;
        scanf("%d %d",&rr,&c);
        for(i=1;i<=rr;i++)
        {
            for(j=1;j<=c;j++)
            {
                scanf(" %c",&a[i][j]);
            }
        }
        for(i=1;i<=rr;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(a[i][j]=='1')
                    l[i][j]=l[i][j-1]+1;
            }
            for(j=c;j>=1;j--)
            {
                if(a[i][j]=='1')
                    r[i][j]=r[i][j+1]+1;
            }
        }
        for(j=1;j<=c;j++)
        {
            for(i=1;i<=rr;i++)
            {
                if(a[i][j]=='1')
                    u[i][j]=u[i-1][j]+1;
            }
            for(i=rr;i>=1;i--)
            {
                if(a[i][j]=='1')
                    d[i][j]=d[i+1][j]+1;
            }
        }
        for(i=1;i<=rr;i++)
        {
            for(j=1;j<=c;j++)
            {
                ans=max({ans,u[i][j]+l[i][j]-1,u[i][j]+r[i][j]-1,d[i][j]+l[i][j]-1,d[i][j]+r[i][j]-1});
            }
        }
        printf("%d\n",ans);
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
        memset(u,0,sizeof u);
        memset(d,0,sizeof d);
    }
    return 0;
}
