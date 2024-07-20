class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {


      int n=grid.size();
      int m=grid[0].size();
      vector<vector<int>> visited(n,vector<int>(m,0));

      queue<pair<pair<int,int>,int>> q; // we will store (row,col),time

      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2){ // if the orange is rotted
                visited[i][j]=2;  // then mark visited in visited array
                q.push({{i,j},0});  // and push it in the queue as we will initialy push all the coordinates of rotten oranges
            }

            
        }
      }

  // these are the coordiantes for traversing the neighbours in four directions
    int deltax[]={-1,0,+1,0};  
    int deltay[]={0,+1,0,-1};

    int t=0;  // to maintain time


      while(!q.empty())
      {
         int row=q.front().first.first;
         int col=q.front().first.second;
         int time=q.front().second;

         t=max(time,t);

         q.pop();
         
         

         //traversing neighbours

         for(int i=0;i<4;i++)
         {
            int newrow=row+deltax[i];
            int newcol=col+deltay[i];

            // checking for the valid conditions 

            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1 && visited[newrow][newcol]!=2)
            {
                visited[newrow][newcol]=2;
                grid[newrow][newcol]=2;

                q.push({{newrow,newcol},t+1});
            }
         }





      }


// checking in the grid that whether we have a fresh orange or not 
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 && visited[i][j]!=2) return -1; 
        }
     }

     return t;

        
    }
};
