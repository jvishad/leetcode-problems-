/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        
        map<Node*,Node*> mp;
        queue<Node*> que;
        que.push(node);
        mp[node] = new Node(node->val);
        while(!que.empty()){
            Node* ff = que.front();
            que.pop();
            for(auto next:ff->neighbors){
                if(mp[next] == NULL){
                    que.push(next);
                    mp[next] = new Node(next->val);
                }
                
                mp[ff]->neighbors.push_back(mp[next]);  
            }
        }
        return mp[node];
    }
};
