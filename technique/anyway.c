#include<stdio.h>
int dp[1010][1010],a[1010][1010];
int main(){
    int x,y,k,i,j,x1,y1;
    scanf("%d %d %d",&x,&y,&k);
    while(k--){
        scanf("%d %d",&x1,&y1);
        a[x1+1][y1+1]=1;
    }
    dp[1][0]=1;
    for(i=1;i<=x+1;i++){
        for(j=1;j<=y+1;j++){
            if(a[i][j]==1)
                dp[i][j]=0;
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                dp[i][j]%=1000000;
            }
        }
    }
    printf("%d\n",dp[x+1][y+1]);
    return 0;
}
