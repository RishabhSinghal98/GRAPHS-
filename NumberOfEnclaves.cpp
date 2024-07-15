class Solution {
public:
    
    void dfs(int row,int col, vector<vector<int>>&visited,vector<vector<int>>& grid)
    {
        visited[row][col]=1;

        int deltax[]={-1,0,+1,0};
        int deltay[]={0,+1,0,-1};

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<4;i++)
        {
            int newrow=row+deltax[i];
            int newcol=col+deltay[i];

            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && visited[newrow][newcol]!=1 && grid[newrow][newcol]==1)
            {
                dfs(newrow,newcol,visited,grid);
            }
        }

    }


    int numEnclaves(vector<vector<int>>& grid) {

    

        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;

        vector<vector<int>> visited(n,vector<int>(m,0));

//Intution :  checking if the element is 1 and not visited then apply dfs and search all 1 that are connected to the boundary zero and mark them visited 

// traversing first and last row
        for(int i=0;i<m;i++)
        {
            if(!visited[0][i] && grid[0][i]==1) // checking if the element is 0 and not visited then apply dfs and search all 0 that are connected to 
            {
                dfs(0,i,visited,grid);
            }

            if(!visited[n-1][i] && grid[n-1][i]==1)
            {
                dfs(n-1,i,visited,grid);
            }
        }
        

        //traversing first column and last column

        for(int i=0;i<n;i++)
        {
            if(!visited[i][0] && grid[i][0]==1)
            {
                dfs(i,0,visited,grid);
            }

            if(!visited[i][m-1] && grid[i][m-1]==1)
            {
                dfs(i,m-1,visited,grid);
            }

        }


// count thoses 1s which are not visited 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and !visited[i][j]) cnt++;
            }
        }

   return cnt;

    }
};