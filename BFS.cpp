#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
  void traversal(vector<int> adj[],int node,vector<int>&ans,vector<int>&visited)
  {
      queue<int> aux; // Declartion
      
      aux.push(node);
      visited[node]=1;
      
      while(!aux.empty())
      {
          int top=aux.front();
          aux.pop();
          ans.push_back(top);
          
          for(auto node : adj[top])
          {
              if(!visited[node])
                {
                  visited[node] = 1;
                  aux.push(node);
                  
                }
          }
        
      }
  }
  

    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        
        vector<int> visited(V,0);
        vector<int> ans;
        
        traversal(adj,0,ans,visited);
        
        
        return ans;
        
        
    }

};



int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
       
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
