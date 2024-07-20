class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
       
        
        vector<int> adjRev[V];
        vector<int> indegree(V,0);
        vector<int> ans;
        queue<int> q;
        
        for(int i=0;i<V;i++)
        {
            for(auto x : adj[i])
            {
                adjRev[x].push_back(i);
                
                indegree[i]++;
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto x : adjRev[node])
            {
                indegree[x]--;
                
                if(indegree[x]==0) q.push(x);
                
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};