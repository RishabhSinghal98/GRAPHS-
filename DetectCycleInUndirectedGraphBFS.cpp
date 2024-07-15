vector<int> adj[V];
        
    // we are making a directed graph from the above input prerequisites
    
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
       
       
// Intution : We are using Kahns Algorithms 
// Here if we get the topologocal order that means there is no cycle and hence courses can be finished easily but if we dont get the topological oder it means there is a cycle and return false;
        vector<int> visited(V,0);
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
	    
	
	  // if we got the topological order that we have stored in ans it means we completed the courses easily hence return ans i.e the topological sort of elements  .  
	    if(ans.size()==V) return ans;

       return {}; // if no order return empty vector
