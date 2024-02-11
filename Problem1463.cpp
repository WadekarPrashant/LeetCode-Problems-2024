class Solution {
    public int cherryPickup(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        
        Integer[][][] dp = new Integer[n][m][m];
        return dfs(grid, n, m, 0, 0, m-1, dp);
    }
    
    public int dfs(int[][] grid, int n, int m, int row, int col1, int col2, Integer[][][] dp) {
        // base case
        if(row<0 || row>=n || col1<0 || col1>=m || col2<0 || col2>=m) return 0;
        
        // return if dp table is populated for current values
        if(dp[row][col1][col2]!=null) return dp[row][col1][col2];
        
        // now iterate through all the possible cherries available in the next row and add them
        // to find the maximum possible cherries collected in the below row by the robots
        int maxcherries = 0;
        for(int i=-1; i<=1; i++) {
            int newcol1 = col1+i;
            for(int j=-1; j<=1; j++) {
                int newcol2 = col2+j;
                maxcherries = Math.max(maxcherries, dfs(grid, n, m, row+1, newcol1, newcol2, dp));
            }
        }
        
        // then we add the current cherry to that count
        int currcherry = 0;
        if(col1==col2) {
            currcherry = grid[row][col1];
        } else {
            currcherry = grid[row][col1] + grid[row][col2];
        }
        
        // and put that value in the dp table and return
        return dp[row][col1][col2] = maxcherries+currcherry; 
    }
}
