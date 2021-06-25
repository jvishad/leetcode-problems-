class Info {
    public:
  int max;
  int min;
  int count;
  bool bst;
  
  Info(){
      max = INT_MIN;
      min = INT_MAX;
      count = 0;
      bst = true;
  }
};

Info helper(Node* root){
    if(root == NULL){
        Info ans;
        return ans;
    }
    
    Info l = helper(root->left);
    Info r = helper(root->right);
    
    
    Info acc;
    
    if(l.bst == true && r.bst == true && (root->data > l.max && root->data < r.min)){
        acc.bst = true;
        acc.count =  1 + (l.count + r.count);
        acc.min = min(l.min,min(r.min,root->data));
        acc.max = max(l.max,max(r.max,root->data));
        return acc;
    }
    
    acc.bst = false;
    acc.count = max(l.count,r.count);
    return acc;
    
   
}

int largestBst(Node *root)
{
	//Your code here
	Info res = helper(root);
	return res.count;
	
}
