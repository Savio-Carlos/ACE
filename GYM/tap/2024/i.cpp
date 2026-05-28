#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> grid; // 0=wet, 1=dry
// Nodes: rows 0..N-1, columns N..N+M-1
// Edges: for each dry square (i,j), edge between i and N+j, with edge_id storing (i,j)
// adj[u] = vector of (neighbor, edge_id)
// used[edge_id] = false initially

int n_nodes;
vector<vector<pair<int,int>>> adj; // adj[u] = {(v, edge_id)}
vector<bool> used_edge;
vector<pair<int,int>> edge_square; // edge_id -> (i,j) dry square
vector<int> iter_ptr; // for Hierholzer's

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    grid.assign(N, vector<int>(M, 0));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c; cin >> c;
            grid[i][j] = (c=='.') ? 1 : 0;
        }
    }
    
    n_nodes = N + M;
    adj.assign(n_nodes, {});
    
    int edge_count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(grid[i][j]==1){
                int u = i, v = N + j;
                adj[u].push_back({v, edge_count});
                adj[v].push_back({u, edge_count});
                edge_square.push_back({i,j});
                edge_count++;
            }
        }
    }
    used_edge.assign(edge_count, false);
    
    // Find vertices with edges (degree > 0)
    vector<int> degree(n_nodes, 0);
    for(int u=0;u<n_nodes;u++) degree[u] = adj[u].size();
    
    // Find connected components (only considering nodes with edges)
    // Check connectivity
    vector<int> comp(n_nodes, -1);
    int start_node = -1;
    for(int u=0;u<n_nodes;u++){
        if(degree[u]>0){ start_node = u; break; }
    }
    if(start_node==-1){
        // No edges = no dry squares. But problem says at least one dry square.
        // Shouldn't happen.
        return 0;
    }
    // BFS
    queue<int> bfs;
    bfs.push(start_node);
    comp[start_node]=0;
    while(!bfs.empty()){
        int u = bfs.front(); bfs.pop();
        for(auto& [v, eid] : adj[u]){
            if(comp[v]==-1){
                comp[v]=0;
                bfs.push(v);
            }
        }
    }
    bool connected = true;
    for(int u=0;u<n_nodes;u++){
        if(degree[u]>0 && comp[u]==-1){ connected=false; break; }
    }
    if(!connected){
        cout << "*" << endl;
        return 0;
    }
    
    // Count odd-degree
    vector<int> odd_nodes;
    for(int u=0;u<n_nodes;u++){
        if(degree[u]%2==1) odd_nodes.push_back(u);
    }
    if(odd_nodes.size()!=0 && odd_nodes.size()!=2){
        cout << "*" << endl;
        return 0;
    }
    
    // Find Eulerian trail/circuit using Hierholzer's
    int start;
    if(odd_nodes.size()==2) start = odd_nodes[0];
    else start = start_node;
    
    iter_ptr.assign(n_nodes, 0);
    vector<int> edge_order; // edges in order of trail
    
    // Iterative Hierholzer's
    stack<int> st;
    st.push(start);
    vector<int> circuit_vertices;
    vector<int> circuit_edges; // edge used to arrive at vertex (size = circuit_vertices.size() - 1)
    // Actually, easier: track stack of (vertex, edge_used_to_enter)
    
    // Let me use a cleaner approach:
    // We maintain a stack of vertices and the edges that led to them.
    // Process: while stack not empty, look at top vertex. If has unused edge, push neighbor along that edge. Else, pop and add to circuit.
    
    stack<pair<int,int>> stk; // (vertex, edge_in)
    stk.push({start, -1});
    
    while(!stk.empty()){
        int u = stk.top().first;
        // Advance iter_ptr to next unused edge
        while(iter_ptr[u] < (int)adj[u].size() && used_edge[adj[u][iter_ptr[u]].second]){
            iter_ptr[u]++;
        }
        if(iter_ptr[u] == (int)adj[u].size()){
            // No more edges, pop
            int eid = stk.top().second;
            stk.pop();
            if(eid != -1) edge_order.push_back(eid);
            // We don't really need circuit_vertices
        } else {
            auto [v, eid] = adj[u][iter_ptr[u]];
            used_edge[eid] = true;
            iter_ptr[u]++;
            stk.push({v, eid});
        }
    }
    
    // edge_order is in reverse
    reverse(edge_order.begin(), edge_order.end());
    
    if((int)edge_order.size() != edge_count){
        // Shouldn't happen if connected and degree condition met
        cout << "*" << endl;
        return 0;
    }
    
    // Assign numbers to dry squares
    vector<vector<int>> answer(N, vector<int>(M, 0));
    for(int k=0;k<edge_count;k++){
        auto [i,j] = edge_square[edge_order[k]];
        answer[i][j] = k+1;
    }
    
    // Output
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << answer[i][j];
            cout << (j==M-1 ? '\n' : ' ');
        }
    }
    
    return 0;
}