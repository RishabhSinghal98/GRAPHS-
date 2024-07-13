
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
   
    void bfstraversal(int row,int col,vector<vector<int>>& visited,vector<vector<char>>& grid)
    {
        visited[row][col]=1;
        queue<pair<int,int>> aux;
        aux.push({row,col});

        int n=grid.size();
        int m=grid[0].size();

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};

        while(!aux.empty())
        {
            int row=aux.front().first;
            int col=aux.front().second;
            aux.pop();

            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {

                    int newrow=row+i;
                    int newcol=col+j;

                    if(newrow>=0 && newcol>=0 && newrow<n && newcol<m 
                    && grid[newrow][newcol]=='1' && visited[newrow][newcol]!=1)
                    {

                    
                
                        visited[newrow][newcol]=1;
                        aux.push({newrow,newcol});
                    }
                    
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {

        int row=grid.size();
        int col=grid[0].size();
        int count=0;

        vector<vector<int>> visited(row,vector<int>(col,0));

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    bfstraversal(i,j,visited,grid);
                    count++;
                }
            }
        }
        return count;
       
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
