vector<int> parent;
vector<int> rank;

int find(int x){
    if(parent[x]==x)
    return x;
    
    return parent[x]=find(parent[x]);
}

void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    
    if(x_parent==y_parent)return ;
    
    if(rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
    }
    else if(rank[x_parent]<rank[y_parent]){
        parent[x_parent]=y_parent;
    }
    else {
        parent[y_parent]=x_parent;
        rank[x_parent]++;
    }
    
}
//Function to detect cycle using DSU in an undirected graph.
int detectCycle(int V, vector<int>adj[]){
    // Code here
    
    parent.resize(V);
    rank.resize(V);
    
    for(int i=0;i<V;i++){
        parent[i]=i;
        rank[i]=0;
    }
    
    
    for(int i=0;i<V;i++){
        for(auto j:adj[i]){
            if(i<j){
                int i_parent=find(i);
                int j_parent=find(j);
                if(i_parent==j_parent)return true;
                Union(i_parent,j_parent);
            }
        }
    }
    return false;
    
}



