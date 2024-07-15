class Solution {
  public:
  
    
    bool isCyclic(int V, vector<int> adj[]) {
       
// Intution : We are using Kahns Algorithms 
// Here if we get the topologocal order that means there is no cycle 
	    vector<int> indegree(V,0);
	    queue<int> q;
	    vector<int> ans;
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto x: adj[i])
	        {
	           indegree[x]++;   
	        }
	    }
	    
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	 
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto x: adj[node])
	        {
	            if(indegree[x]==0) // if indegree is 0 then push it in queue.
	            {
	                q.push(x);
	            }
	            
	            else{ // else decrease the indegree and if then it becomes zero then push it in the queue.
	                indegree[x]--;
	                if(indegree[x]==0) q.push(x);
	            }
	        }
	    }
	    
	
	  if(ans.size()==V) return false; // if we got the topological order that we have stored in ans that means no cycle

       return true; // if no order it means cycle

    }
};