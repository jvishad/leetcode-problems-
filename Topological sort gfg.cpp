class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int u,stack<int> &st,vector<bool> &vis,vector<int> adj[]){
	    if(!vis[u]){
	        vis[u] = true;
	    }
	    for(auto it:adj[u]){
	        if(!vis[it]){
	            dfs(it,st,vis,adj);
	        }
	    }
	    st.push(u);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    vector<bool> vis(V,false);
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,st,vis,adj);
	        }
	    }
	    while(st.empty() == false){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
};
