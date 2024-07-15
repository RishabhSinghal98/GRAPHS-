
class Solution
{
	public:
	
	void dfs(int node,vector<int>&visited,vector<int> adj[],stack<int>&stk)
	{
	    visited[node]=1;
	    
	    for(auto x : adj[node])
	    {
	        if(!visited[x])
	        {
	            dfs(x,visited,adj,stk);
	        }
	    }
	    stk.push(node); // if dfs call of a node is completed then on returning to previous call push that node into stack
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    vector<int> visited(V,0);
	    vector<int> ans;
	    stack<int> stk;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            dfs(i,visited,adj,stk);
	        }
	    }
	    
	    while(stk.size()>0)
	    {
	        ans.push_back(stk.top());
	        stk.pop();
	    }
	    return ans;
	}
};

