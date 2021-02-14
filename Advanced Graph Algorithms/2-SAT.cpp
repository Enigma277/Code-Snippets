struct  TwoSAT{
    static const int MAXN = 1e5+5;
    int n;
    vector<int> graph[2*MAXN], reverse_graph[2*MAXN];
    vector<bool> visited;
    vector<int> comp_id;
    stack<int> order;
    vector<bool> assignment;
    
    int X(int x){
        return 2*x;
    }

    int negation_X(int x){
        return 2*x+1;
    }
    
    void init(int vertex){
        n = vertex;
        visited.assign(2*vertex+2, false);
        comp_id.assign(2*vertex + 2, -1);
        assignment.assign(2*vertex+2, false);
        for(int i=1;i<=vertex;i++){
            graph[X(i)].clear();
            graph[negation_X(i)].clear();
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
    int get_assignment(int i){
        return assignment[X(i)];
    }

    bool solve_2SAT(){
        for(int i = 1; i <= n ;i++){
            if(!visited[X(i)]){
                dfs1(X(i));
            }
            if(!visited[negation_X(i)]){
                dfs1(negation_X(i));
            }
        }
        int j = 0;
        while(!order.empty()){
            int node = order.top();
            order.pop();
            if(comp_id[node]==-1){
                dfs2(node, j++);
            }
        }
        for(int i=1; i<=n; i++){
            if(comp_id[X(i)]==comp_id[negation_X(i)]){
                return false;
            }
            if(comp_id[X(i)] > comp_id[negation_X(i)]){
                assignment[X(i)] = true;
            }else{
                assignment[negation_X(i)] = true;
            }
        }
        return true;
    }
}two_SAT;

//Usage
//Problem : https://codeforces.com/contest/776/problem/D, 
//Solution: https://codeforces.com/contest/776/submission/85993155
