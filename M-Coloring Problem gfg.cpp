// problem link - https://practice.geeksforgeeks.org/problems/m-coloring-problem

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool possible(int n,int node,bool graph[101][101],int color[],int col){
    for(int i=0;i<n;i++){
        if(i!=node && graph[i][node] == 1 && color[i] == col){
            return false;
        }
    }
    return true;
}

bool func(int node,int V,bool graph[101][101],int color[],int m){
    if(node == V){
        return true;
    }
    
    for(int col = 1;col <= m;col++){
        if(possible(V,node,graph,color,col) == true){
            color[node] = col;
            if(func(node+1,V,graph,color,m) == true){
                return true;
            }
           else{
                color[node] = 0;
            }
        }
        // return false;
    }
    return false;
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V];
    for(int i=0;i<V;i++){
        color[i] = 0;
    }
    if(func(0,V,graph,color,m) == true){
        return true;
    }
    return false;
}
