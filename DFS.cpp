
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  void traversal(int node,vector<int>&vis,vector<int>&ans,vector<int> adj[])
  {
      vis[node]=1;
      ans.push_back(node);
      
      for(auto it: adj[node])
      {
          if(!vis[it])
          {
              traversal(it,vis,ans,adj);
          }
      }
      
  }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited (V,0);
        vector<int> ans;
        
        traversal(0,visited,ans,adj);
        
        return ans;
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
