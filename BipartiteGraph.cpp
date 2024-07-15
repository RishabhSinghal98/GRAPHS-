class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        vector<int> color(n,-1); // initializing the graph with -1 color
        
        // running a loop to make sure if there are disconnected components in the graph
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                queue<int> q;
                q.push(i);
                color[i]=0; // marking the starting node with color 0 
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    
                    for(auto x : graph[node]){
                        
                        if(color[x]==-1) // this means the node is not colored
                 {
                    // so colour it with oppposite color to its adjacent node

                    color[x]=!color[node]; // since the adjacent  node which was pushed into queue
                    q.push(x);

                 }

               // checking if nodes color is equal to adjacent node or not  
                else if(color[x]==color[node]) return false;

                }
            }
        }
    
    }

     return true;


       
            

        
        
       
    }
};