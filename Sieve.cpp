vector<int>prime;
void sieve(int n) {
  vector<bool>check(n+1, true);
  int limit = sqrt(n)+1;
  for(int i = 3; i <= limit; i += 2) {
    if(check[i] == false) continue;
    for(int j = i*i; j <= n; j += i) {
        check[j] = false;
    }
  }
  prime.push_back(2);
  for(int i = 3; i <= n; i += 2) {
    if(check[i] == true) {
      prime.push_back(i);
    }
  }
}
