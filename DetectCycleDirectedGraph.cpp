
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
   bool check(int node,vector<int>&visited, vector<int>&pathvisited,vector<int> adj[]){
       
       visited[node]=1;
       pathvisited[node]=1;
       
       for(auto x: adj[node])
       {
           if(!visited[x])
           {
               if(check(x,visited,pathvisited,adj)== true) return true;
           }
           else if(visited[x] && pathvisited[x]) return true; // main condition 
       }
       
       pathvisited[node]=0; // on going back we will mark the path visited 0
       return false;
   }
   
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> visited(V,0);
        vector<int> pathvisited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            if(check(i,visited,pathvisited,adj)==true) return true;
        }
        
        return false;
    }
};



int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends