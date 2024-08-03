Problem Link : https://www.geeksforgeeks.org/problems/number-of-provinces/1
class Solution {
public:

    void dfs(vector<int> adj[], vector<int>&vis,int node)
    {
        vis[node]=1;

        for(auto it : adj[node])
        {     
            if(!vis[it] )
            {
                dfs(adj,vis,it);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector <int> adj[V];
        vector <int> visited(V,0);
        int count=0;

       for(int i=0;i<V;i++)
       {
        for(int j=0;j<V;j++)
        {
            if(isConnected[i][j] == 1 && i != j) { 
                adj[i].push_back(j); 
                adj[j].push_back(i); 
                }
        }
       }

       for(int i=0;i<V;i++)
       {
           if(!visited[i])
           {
             count++; // this means we are going for traversal and each time we go for traversal that means we are encountering new province
            dfs(adj,visited,i);
           }
       }

     return count;
        
    }
};

