#include<queue>

class Solution 
{
    public:
    bool helper(int u,int p,vector<int> adj[],vector<bool>&vis){
        queue<pair<int,int>>que;
        que.push({u,p});
        vis[u] = true;
        while(!que.empty()){
            int node = que.front().first;
            int parent = que.front().second;
            que.pop();
            for(auto it:adj[node]){
                if(vis[it] == true && it!=parent){
                    return true;
                }
                if(!vis[it]){
                    que.push({it,node});
                    vis[it] = true;
                }
            }
        }
        return false;
    }
    
    
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(V,false);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(helper(i,-1,adj,vis) == true){
	                return true;
	            }
	        }
	    }
	    return false;
	}
};
