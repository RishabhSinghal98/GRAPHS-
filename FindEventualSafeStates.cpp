class Solution {
public:
bool checkdfs(int node,vector<int>&visited,vector<int>&check,vector<int>&pathvisited,vector<vector<int>>& adj){
       
       visited[node]=1;
       pathvisited[node]=1;
       check[node]=0;
       
       for(auto x: adj[node])
       {
           if(!visited[x])
           {
               if(checkdfs(x,visited,check,pathvisited,adj)== true) return true;
           }
           else if(visited[x] && pathvisited[x]) return true;
       }
       
       check[node]=1; // this means we are considering the node to be safe node
       pathvisited[node]=0; // on going back we will mark the path visited 0
       return false;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {

        int V=adj.size();
        vector<int> visited(V,0);
        vector<int> pathvisited(V,0);

        vector<int> check(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            checkdfs(i,visited,check,pathvisited,adj);
        }

        vector<int> ans;

        for(int i=0;i<V;i++)
        {
            if(check[i]==1) ans.push_back(i);
        }

        return ans;



        
    }
};