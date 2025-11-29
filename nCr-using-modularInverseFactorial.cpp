int MOD = 1e9+7;
int mul(int a, int b) { return (a*b)%MOD; }
int modInv(int a){
  int result = 1, base = a, pow = MOD-2;
  while(pow > 0) {
    if(pow&1) {
      result = mul(result, base);
    }
    base = mul(base, base);
    pow = pow >> 1;
  }
  return result;
}
vector<int>fact;
vector<int>invFact;
void factCalc(int n) {
  fact.resize(n+1);
  invFact.resize(n+1);
  fact[0] = 1;
  for(int i = 1; i <= n; i++) {
    fact[i] = mul(fact[i-1], i);
  }
  invFact[n] = modInv(fact[n]);
  for(int i = n-1; i >= 0; i--) {
    invFact[i] = mul(invFact[i+1], i+1);
  }
}
int nCr(int n, int r) {
  if(r < 0 || r > n) return 0;
  return mul(mul(fact[n], invFact[r]), invFact[n-r]);
}
