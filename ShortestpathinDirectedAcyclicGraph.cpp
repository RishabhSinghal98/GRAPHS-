class Solution {
  public:
  
  void dfs(int node , vector<vector<pair<int,int>>> &adj, vector<int> & visited, stack<int> & stk)
  {
      visited[node]=1;
      
      for(auto x : adj[node])
      {
          int u=x.first;
          if(!visited[u])
          {
              dfs(u,adj,visited,stk);
          }
      }
      
      stk.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        
     
       
       // Step 1 - Create a Graph 
        vector<vector<pair<int,int>>> adj(N);
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            
            adj[u].push_back({v,weight});
        }
        
        // Step 2 - Find Topological Sort
        vector<int> visited(N,0);
        stack<int> stk;
        
        for(int i=0;i<N;i++)
        {
            if(!visited[i]) dfs(i,adj,visited,stk);
        }
        
        
        // Fill the distance matrrix

         
         vector<int> distance (N,1e9);
         distance[0]=0 ; //  assuming 0 to be starting node
         
         while(!stk.empty())
         {
             int node=stk.top();
             stk.pop();
             
             for(auto x : adj[node])
             {
                 int u=x.first;
                 int wt=x.second;
                 
                 if(distance[node] + wt < distance[u])
                 {
                     distance[u]=distance[node]+wt;
                 }
                 
                 
             }
             
         }
         
      for (int i = 0; i < N; i++) {
        if (distance[i] == 1e9) distance[i] = -1;
      }
        return distance;
        
    }
};
