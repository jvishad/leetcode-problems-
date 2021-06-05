vector<int> bottomView(Node *root)
    {
        //Your code here
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        queue<pair<Node*,int>> que;
        map<int,int> mp;
        que.push({root,0});
        while(!que.empty()){
            Node* ff = que.front().first;
            int h = que.front().second;
            que.pop();
                mp[h] = ff->data;
            if(ff->left!=NULL){
                que.push({ff->left,h-1});
            }
            if(ff->right!=NULL){
                que.push({ff->right,h+1});
            }
            
            
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
