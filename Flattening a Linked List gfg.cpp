Node* merging(Node* l1,Node* l2){
    if(l1 == NULL){
        return l2;
    }
    else if(l2 == NULL){
        return l1;
    }
    
    Node* temp = new Node(0);
    Node* res = temp;
    // res->bottom = temp;
    
    while(l1!= NULL || l2!= NULL){
        if(l1 == NULL){
            temp->data = l2->data;
            l2 = l2->bottom;
        }
        else if(l2 == NULL){
            temp->data = l1->data;
            l1 = l1->bottom;
        }
        else if(l1->data > l2->data){
            temp->data = l2->data;
            l2 = l2->bottom;
        }
        else if(l1->data <= l2->data){
             temp->data = l1->data;
            l1 = l1->bottom;
        }
        if(l1 || l2){
            temp->bottom = new Node(0);
            temp = temp->bottom;
        }
    }
    return res;

}
    
    
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL){
       return root;
   }
   
  root->next = flatten(root->next);
  root = merging(root,root->next);
  return root;
}