class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    vector<int> ans;
	    queue<int> que;
	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0){
	            que.push(i);
	        }
	    }
	        while(!que.empty()){
	            int f = que.front();
	            ans.push_back(f);
	            que.pop();
	            for(auto it:adj[f]){
	                if(indegree[it]){
	                    indegree[it]--;
	                    if(indegree[it] == 0){
	                        que.push(it);
	                    }
	                }
	                
	            }
	        }
	    return ans;	    
	}
};
