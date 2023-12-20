#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;

void fastInputOutput() { cin.tie(nullptr)->sync_with_stdio(false); }

#define usefile()                    \
  ifstream cin("../test_input.txt"); \
  ofstream cout("../out.txt");       \
  std::cin.rdbuf(cin.rdbuf());       \
  std::cout.rdbuf(cout.rdbuf())

string delim = " ";
#define print(x) cout << setprecision(16) << fixed << x << endl
#define print2(x, y) cout << x << delim << y << endl
#define print3(x, y, z) cout << x << delim << y << delim << z << endl

template <typename T>
void printArr(T &arr) {
  for (auto x : arr) cout << x << " ";
  cout << endl;
}
void printArr(vector<pair<long long, string>> &arr) {
  for (auto x : arr) cout << " (" << x.first << ", " << x.second << ") ";
  cout << endl;
}
template <typename T>
void printArr(vector<vector<T>> &arr) {
  for (auto &x : arr) printArr(x);
}

string bin_string(long long num) {
  if (num == 0) return "0";
  string res = "";
  while (num > 0) {
    res += (num & 1) + '0';
    num >>= 1;
  }
  reverse(res.begin(), res.end());
  print(res);
  return res;
}
string bin_string_fixed(long long num, int sz = 10) {
  if (num == 0) return "0";
  string res = "";
  while (num > 0) {
    res += (num & 1) + '0';
    num >>= 1;
  }
  while (res.size() < sz) res.push_back('0');
  print(res);
  return res;
}

#define ll long long
#define lb long double
const int INF = (int)2e9;
const ll LINF = (ll)4e18;
ll mpow(ll x, ll y, ll p) {
  ll res = 1;
  if (y == 0) return 1;
  x = x % p;
  if (x == 0) return 0;  // In case x is divisible by p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;  // y = y/2
    x = (x * x) % p;
  }
  return res;
}

ll popcount(ll num) { return __builtin_popcount((unsigned int)num); }

ll hashNum(ll a) { return a * (a + 1346) * (a + 9185); }
void extendVector(vector<ll> &v, vector<ll> &other) {
  for (auto val : other) v.push_back(val);
}
map<ll, ll> coordCompress(vector<ll> &arr) {
  set<ll> st(arr.begin(), arr.end());
  map<ll, ll> mp;
  ll idx = 1;
  for (auto &x : st) mp[x] = idx++;
  return mp;
}

#define tp tuple<ll, ll, ll>
vector<vector<ll>> dirs = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // right, down, left, up
vector<vector<ll>> dirsDiag = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                               {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
ll strHashMult = 911382323;
ll strHashMod = 972663749;

// using lm = ::atcoder::modint1000000007;
#define ll long long
#define pi pair<ll, ll>
// get the bit set value at index idx
#define bit(num, idx) ((num >> idx) & 1)
void printArr(vector<pi> &arr) {
  for (auto x : arr) cout << "(" << x.first << "," << x.second << ") ";
  cout << endl;
}
ll Combination(ll n, ll k) {
  long double res = 1;
  for (int i = 1; i <= k; ++i) res = res * (n - k + i) / i;
  return (ll)(res + 0.01);
}
vector<string> splitWord(string &s) {
  istringstream iss(s, istringstream::in);
  vector<string> words;
  string word;
  while (iss >> word) words.push_back(word);
  return words;
}

// using lm = ::atcoder::modint1000000007;
using lm = ::atcoder::modint998244353;

#define ll long long
#define lb long double
#define pi pair<ll, ll>
// #define tpp tuple<ll, ll, ll>
#define tpp tuple<string, ll, string>
ll MOD = 1e9 + 7;
ll MX = 1e15;

class Solution {
 public:
  ll n, m;
  ll answer = 0;
  map<string, ll> mp;
  vector<vector<tpp>> arr;
  map<char, ll> chMap = {
      {'x', 0},
      {'m', 1},
      {'a', 2},
      {'s', 3},
  };
  void run() {
    cin >> n;
    arr.resize(n);
    for (ll idx = 0; idx < n; idx++) {
      string node, df, cond, nxt;
      cin >> node >> df;
      mp[node] = idx;
      ll q;
      cin >> q;
      for (ll i = 0; i < q; i++) {
        cin >> cond >> nxt;
        string cond1 = cond.substr(0, 2);
        ll val = stoll(cond.substr(2));
        arr[idx].push_back({cond1, val, nxt});
      }
      arr[idx].push_back({"", 0, df});
    }
    string startFunc = "in";
    pi start = {1, 4000};
    vector<pi> inp;
    for (ll i = 0; i < 4; i++) inp.push_back(start);
    solve(inp, startFunc);
    print(answer);
  }
  void solve(vector<pi> inp, string &func) {
    if (func == "A") {
      ll res = 1;
      for (auto &x : inp) {
        res = res * (x.second - x.first + 1);
      }
      answer += res;
      return;
    }
    if (func == "R") return;
    auto funcs = arr[mp[func]];
    string cond, nxtFunc;
    ll val;
    ll sz = funcs.size();
    for (ll i = 0; i < sz; i++) {
      tie(cond, val, nxtFunc) = funcs[i];
      if (cond.empty()) {
        solve(inp, nxtFunc);
        return;
      }
      char ch = cond[1];
      ll g = chMap[cond[0]];
      vector<pi> inp2(inp.begin(), inp.end());
      if (ch == '>') {
        ll lo = max(val + 1, inp[g].first);
        pi tmp = {lo, inp[g].second};
        if (tmp.second > tmp.first) {
          inp2[g] = tmp;
          solve(inp2, nxtFunc);
        }
        tmp = {inp[g].first, lo - 1};
        if (tmp.second < tmp.first) return;
        inp[g] = tmp;
      }
      if (ch == '<') {
        ll hi = min(val - 1, inp[g].second);
        pi tmp = {inp[g].first, hi};
        if (tmp.second > tmp.first) {
          inp2[g] = tmp;
          solve(inp2, nxtFunc);
        }
        tmp = {hi + 1, inp[g].second};
        if (tmp.second < tmp.first) return;
        inp[g] = tmp;
      }
    }
  }
};

int main() {
  fastInputOutput();
  usefile();

  Solution sol;
  sol.run();

  return 0;
}
