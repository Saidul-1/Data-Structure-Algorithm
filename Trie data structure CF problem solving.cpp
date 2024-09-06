//Problem: https://codeforces.com/problemset/problem/928/D

#include<bits/stdc++.h>
using namespace std;

struct trie {
  map<char, trie>mp;
  bool f = false;
};
trie* root = new trie();
int suggest(string s) {
  int lastf = 0, skip = 0, ans = 0;
  trie* tmp = root;
  for(int i = 0; i < s.size(); i++) {
    if(((tmp->mp.size()) > 1) || ((tmp->mp.size()) == 1) && (tmp->mp.find(s[i]) == tmp->mp.end())) {
      lastf = i;
      skip = 0;
    }
    else if(tmp->f) {
      skip = i-lastf-1;
      lastf = i;
    }
    if(tmp->mp.find(s[i]) == tmp->mp.end()) {
      trie newblc;
      tmp->mp[s[i]] = newblc;
    }
    tmp = &(tmp->mp[s[i]]);
  }
  if((tmp->mp.empty()) && (tmp->f)){ 
    skip = s.size()-lastf-1;
  }
  tmp->f = true;
  if(!(tmp->mp.empty())) return 0;
  return max(0, (skip-1));
}
int32_t main() {
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  string s;
  int strokes = 0;
  while(getline(cin, s)) {
    strokes += (s.size()+1);
    int ind = 0, len = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] >= 'a' && s[i] <= 'z') len++;
      else {
        if(len > 0) {
          strokes -= suggest(s.substr(ind, len));
        }
        ind = i+1, len = 0;
      }
    }
    if(len > 0) {
      strokes -= suggest(s.substr(ind, len));
    }
  }
  cout << strokes;
  return 0;
}
