class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        
        vector<vector<int>> visited(n,vector<int>(m,0)); 
        vector<vector<int>> distance(n,vector<int>(m)); 
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)  // if the cell is 0 it means we dont require any distance 
                {
                    q.push({{i,j},0}); // so push the coordinates and 0 distance as we dont require any distance as we are already on 0
                    visited[i][j]=1;
                    distance[i][j]=0; // mark the distance matrxi with 0 
                }
            }
        }

       // coordinates for traversal to the neighbours in four directions 
        int deltax[]={-1,0,+1,0};
        int deltay[]={0,+1,0,-1};
        
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int newrow=row+deltax[i];
                int newcol=col+deltay[i];
                
                // checking for valid neighbours
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && visited[newrow][newcol]!=1)
                {
                    distance[newrow][newcol]=dist+1; // marking the distance matrix with previous distance+1
                    visited[newrow][newcol]=1;
                    
                    q.push({{newrow,newcol},dist+1}); // pushing the neighbour into queue along with distance+1
                }
                
            }
            
            
            
        }
        
        
        return distance;
        
        
    }
};