class Solution {
public:
    
    void dfs(int row,int col, vector<vector<int>>&visited,vector<vector<char>>& board)
    {
        visited[row][col]=1;

        int deltax[]={-1,0,+1,0};
        int deltay[]={0,+1,0,-1};

        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<4;i++)
        {
            int newrow=row+deltax[i];
            int newcol=col+deltay[i];

            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && visited[newrow][newcol]!=1 && board[newrow][newcol]=='O')
            {
                dfs(newrow,newcol,visited,board);
            }
        }

    }


    void solve(vector<vector<char>>& board) {

       
        

        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

//Intution :  checking if the element is 0 and not visited then apply dfs and search all 0 that are connected to the boundary zero and mark them visited 

// traversing first and last row
        for(int i=0;i<m;i++)
        {
            if(!visited[0][i] && board[0][i]=='O') // checking if the element is 0 and not visited then apply dfs and search all 0 that are connected to 
            {
                dfs(0,i,visited,board);
            }

            if(!visited[n-1][i] && board[n-1][i]=='O')
            {
                dfs(n-1,i,visited,board);
            }
        }
        

        //traversing first column and last column

        for(int i=0;i<n;i++)
        {
            if(!visited[i][0] && board[i][0]=='O')
            {
                dfs(i,0,visited,board);
            }

            if(!visited[i][m-1] && board[i][m-1]=='O')
            {
                dfs(i,m-1,visited,board);
            }

        }


// Those 0 which are not connected to boundary zeros means that they can be converted to X so change them to X
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !visited[i][j]) board[i][j]='X';
            }
        }


    }
};