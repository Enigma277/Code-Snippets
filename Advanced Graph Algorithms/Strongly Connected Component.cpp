struct  SCC{
    static const int MAXN = 1e5+5;
    int n, comp = 0;
    vector<int> graph[MAXN], reverse_graph[MAXN];
    vector<bool> visited;
    vector<int> comp_id;
    stack<int> order;
    set<int> compressed_DAG[MAXN];

    void init(int vertex){
        n = vertex;
        comp = 0;
        visited.assign(vertex+1, false);
        comp_id.assign(vertex+1, -1);
        for(int i=1;i<=n;i++){
            graph[i].clear();
            reverse_graph[i].clear();
            compressed_DAG[i].clear();
        }
    }
    
    void add_edge(int u , int v){
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
    }
    
    void dfs1(int node){
        visited[node] = true;
        for(int adj: graph[node]){
            if(!visited[adj]){
                dfs1(adj);
            }
        }
        order.push(node);
    }
    
    void dfs2(int node, int id){
        comp_id[node] = id;
        for(int adj:reverse_graph[node]){
            if(comp_id[adj]==-1){
                dfs2(adj,id);
            }
        }
    }
    
    void get_SCC(){
        for(int i = 1; i <= n ;i++){
            if(!visited[i]){
                dfs1(i);
            }
        }
        
        while(!order.empty()){
            int node = order.top();
            order.pop();
            if(comp_id[node]==-1){
                dfs2(node, comp++);
            }
        }

        for(int i = 1; i <= n; i++){
            for(int adj:graph[i]){
                if(comp_id[i]!=comp_id[adj]){
                    compressed_DAG[comp_id[i]].insert(comp_id[adj]);
                }
            }
        }
    }
}SCC;

//Usage
//Problem: https://codeforces.com/contest/999/problem/E
//Solution: https://codeforces.com/contest/999/submission/86002697
