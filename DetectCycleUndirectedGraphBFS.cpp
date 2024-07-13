
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
   
   bool detect(int node,vector<int>&visited,vector<int>adj[])
   {
       queue<pair<int,int>> q;
       q.push({node,-1});
       visited[node]=1;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            
            q.pop();
            
            
            for(auto x: adj[node])
            {
               
                if(!visited[x])
                { 
                    visited[x]=1;
                    q.push({x,node});
                }
                 else if(x!=parent)
                {
                    return true;
                }
            }
            
            
        }
        
        
        return false;
       
   }
  
    
    bool isCycle(int V, vector<int> adj[]) {
       
        
        vector<int> visited(V,0);
        
       
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            if(detect(i,visited,adj)) return true;;
        }
        
        return false;
        
        
        
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
