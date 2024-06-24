#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
#define pb push_back    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)

#define int long long int
typedef uint64_t ull;
struct H {
  ull x; H(ull _x=0) : x(_x) {}
  H operator+(H o) { return x + o.x + (x + o.x < x); }
  H operator-(H o) { return *this + ~o.x; }
  H operator*(H o) { auto m = (__uint128_t)x * o.x;
    return H((ull)m) + (ull)(m >> 64); }
  ull get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};
static const H C = rng(1e10,1e12); // (order ~ 3e9; random also ok)

struct HashInterval {
  vector<H> ha, pw;
  HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
    pw[0] = 1;
        for (int i = 0; i < sz(str); i++)
      ha[i+1] = ha[i] * C + str[i],
      pw[i+1] = pw[i] * C;
  }
  H hashInterval(int a, int b) { // hash [a, b)
    return ha[b] - ha[a] * pw[b - a];
  }
    void insert(char a){
        ha.pb(ha.back()*C + a);
        pw.pb(pw.back()*C);
    }
};
// Print the number of occurance of the pattern in the given string s;
int32_t main() {
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  string s, pat;
  cin >> s >> pat;
  int n = s.size(), m = pat.size();
  HashInterval str = HashInterval(s);
  HashInterval pt = HashInterval(pat);
  H patH = pt.hashInterval(0, m);
  int ans = 0;
  for(int i = 0; i <= n-m; i++) {
    if(patH == str.hashInterval(i, i+m)) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
