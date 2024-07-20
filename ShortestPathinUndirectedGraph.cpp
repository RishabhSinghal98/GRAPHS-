class Solution {
  public:

    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        
       // Step 1 - Create a Graph 
        vector<vector<pair<int,int>>> adj(N);
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
          // since its undirected graph therefore create and edge for both nodes 
            adj[u].push_back({v,1});
            adj[v].push_back({u,1});
        }
        
       
        
        // Fill the distance matrix
        
        queue<pair<int,int>> q;
        vector<int> distance (N,1e9);
        
        q.push({src,0}); // push the source node and initially the distance 0
        
        distance[src]=0 ;  // mark the src node at distance vector with zero
         
        
         while(!q.empty())
         {
             int node=q.front().first;  // we take the node
             q.pop();
             
             for(auto x : adj[node]). // traverse in the neighbour of the above node
             {
                 int u=x.first; // node
                 int wt=x.second; // weight
                 
                 if(distance[node] + wt < distance[u])
                 {
                     distance[u]=distance[node]+wt;
                     q.push({u,wt});
                 }
                 
                 
             }
             
         }
         for(int i=0;i<distance.size();i++){
             if(distance[i]==1e9)
             {
                 distance[i]=-1;
             }
         }
     
        return distance;
        
    }
};