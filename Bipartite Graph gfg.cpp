class Solution {
public:
    bool helper(int u,vector<int> &color,vector<int> adj[]){
        queue<int> que;
        que.push(u);
        color[u] = 1;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it] = 1 - color[node];
                    que.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i] == -1){
	        if(helper(i,color,adj) == false){
	            return false;
	        }
	        }
	    }
	    return true;
	}

};          

// tc = O(N+E)
// sc = O(N+E) + O(N) + O(N)
