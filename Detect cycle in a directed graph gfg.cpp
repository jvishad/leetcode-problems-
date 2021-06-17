class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool dfs(int u,vector<int> adj[],vector<bool> &vis,vector<bool> &dfsvis){
	    vis[u] = true;
	    dfsvis[u] = true;
	    for(auto it:adj[u]){
	        if(!vis[it]){
	            if(dfs(it,adj,vis,dfsvis) == true){
	                return true;
	            }
	        }
	        else if(vis[it] == true && dfsvis[it] == true){
	            return true;
	        }
	    }
	    dfsvis[u] = false;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<bool> vis(V,false);
	   	vector<bool> dfsvis(V,false);
	   	for(int i=0;i<V;i++){
	   	    if(!vis[i]){
	   	        if(dfs(i,adj,vis,dfsvis) == true){
	   	            return true;
	   	        }
	   	    }
	   	}
	   	return false;
	}
};
