
int dfs(int m,int n,int **dp) {
    if((m==0) || (n==0)) return 1;
    else if(dp[m][n]) {
        return dp[m][n];
    } 
    if((m-1) >-1) {
        dp[m][n]+= dfs(m-1,n,dp);
    }
    if((n-1)>-1) {
        dp[m][n]+=dfs(m,n-1,dp);
    }
    return dp[m][n];
}

int uniquePaths(int m, int n){
    int **dp = (int**)calloc(m,sizeof(int*));
    for(int i=0;i<m;i++) {
        dp[i] = (int *)calloc(n,sizeof(int));
    }
    int result = dfs(m-1,n-1,dp);
    for(int i=0;i<m;i++) free(dp[i]);
    free(dp);
    return result;
}

