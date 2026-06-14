class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>> dp(grid.size()+1,vector<long long>(grid[0].size()+1,0));
        dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                int right =(j+1<n)? dp[i][j+1]:INT_MAX;
                int bottom =(i+1<m)? dp[i+1][j]:INT_MAX;
                dp[i][j]= grid[i][j]+ min(right,bottom);
            }
        }
        return (int)dp[0][0];
    }
};
