#include<bits/stdc++.h>
using namespace std;

class HopcroftKarp {
public:
  vector<int>l, r, d;
  vector<vector<int>> adj;
  int n, m;
  HopcroftKarp(int n, int m) {// constructor
    adj.resize(n+1);// adjacency table; key: left nodes, value: right nodes
    d.resize(n+1);// pair distance
    l.resize(n+1, 0);// left to right pairs 
    r.resize(m+1, 0);// right to left pairs
    this->n = n, this->m = m;
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
  }
  int maxMatch() { // maximum possible number of pairs
    int match = 0;
    while(bfs()) {
      for(int i = 1; i <= n; i++) {
        if(l[i] == 0 && dfs(i)) {// for each unmatched nodes, check if it is possible to match it by extending an existing path
          match++;
        }
      }
    }
    return match;
  }
private:
  bool bfs() {
    queue<int>q;
    for(int i = 1; i <= n; i++) {
      if(l[i] == 0) {
        d[i] = 0;
        q.push(i);
      }
      else {
        d[i] = INT_MAX;
      }
    }
    d[0] = INT_MAX;// 0 isn't a node. Rather, it indicates whether a augmenting path is found
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      if(d[u] >= d[0]) {//after getting a valid path, we can skip some nodes which won't make path
        break;
      }
      for(auto v : adj[u]) {
        if(d[r[v]] == INT_MAX) {
          d[r[v]] = d[u]+1;
          q.push(r[v]);
        }
      }
    }
    return d[0] != INT_MAX;//if any path found, d[0] should have updated to a distanse less than INT_MAX
  }
  bool dfs(int u) {
    if(u == 0) return true;
    for(auto v : adj[u]) {
      if(d[r[v]] == d[u]+1 && dfs(r[v])) {
        l[u] = v;
        r[v] = u;// if an extended path is found, update the existing matches;
        return true;
      }
    }
    d[u] = INT_MAX;
    return false;
  }
};
int32_t main() {
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int n, m, e;// n: number of nodes in left, m: number of nodes in right, e: number of edges
  cin >> n >> m >> e;
  HopcroftKarp hk(n, m);
  while(e--) {
    int u, v;
    cin >> u >> v;
    hk.addEdge(u, v);
  }
  cout << hk.maxMatch() << "\n";
  return 0;
}
