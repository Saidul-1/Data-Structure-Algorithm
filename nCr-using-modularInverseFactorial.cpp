int MOD = 1e9+7;
int modInv(int a){
  int result = 1, base = a, pow = MOD-2;
  while(pow > 0) {
    if(pow&1) {
      result = (result*base)%MOD;
    }
    base = (base*base)%MOD;
    pow = pow >> 1;
  }
  return result;
}
vector<int>fact(1e6+1);
vector<int>invFact(1e6+1);
void factCalc() {
  fact[0] = fact[1] = 1;
  for(int i = 2; i <= 1e6; i++) {
    fact[i] = (fact[i-1]*i)%MOD;
  }
  invFact[1e6] = modInv(fact[1e6]);
  for(int i = 1e6-1; i >= 0; i--) {
    int k = invFact[i+1]*(i+1);
    invFact[i] = (invFact[i+1]*(i+1))%MOD;
  }
}
int nCr(int n, int r) {
  return (fact[n]*((invFact[r]*invFact[n-r])%MOD))%MOD;
}
