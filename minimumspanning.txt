    // vector<int> parent; 
    // vector<int> rank; 
  
    
    
    int find(int x){
        if(parent[x]==x)
        return x;
        return parent[x]=find(parent[x]);
        
    }
    
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        
        if(x_parent==y_parent)return ;
        
        if(rank[x_parent]==rank[y_parent]){
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else {
            parent[x_parent]=y_parent;
        }
    }
    
    int kruskal(vector<vector<int>>&vec){
        
        int sum=0;
        for(auto &ele:vec){
            int x_parent=find(ele[0]);
            int y_parent=find(ele[1]);
            
            if(x_parent!=y_parent){
                sum+=ele[2];
                Union(ele[0],ele[1]);
            }
        }
        return sum;
    }
    
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> vec;
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                vec.push_back({i,j[0],j[1]});
            }
        }
        auto comparator=[&](vector<int>&v1,vector<int>&v2){
            return v1[2]<v2[2];
        };
        sort(begin(vec),end(vec),comparator);
        
        return kruskal(vec);
        
        
        
        
    }
};