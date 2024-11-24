#include<bits/stdc++.h>
using namespace std;
#define int long long int

int mx = 1e18;
int32_t main() {
  ios::sync_with_stdio(false);cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  // nxn matrix
  vector<vector<int>>matrix(n, vector<int>(n, mx));
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    matrix[a][b] = matrix[b][a] = min(matrix[a][b], c);
  }
  for (int i = 0; i < n; i++) {
    matrix[i][i] = 0;
  }
  for(int k = 0; k < n; k++) { // here k is intermediate node
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
      }
    }
  }
  // query
  while(q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if(matrix[a][b] == mx) cout << "-1\n";
    else cout << matrix[a][b] << "\n";
  }
  return 0;
}