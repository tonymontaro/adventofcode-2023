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
#define tpp tuple<ll, ll, ll, ll, ll>
ll MOD = 1e9 + 7;
ll MX = 1e15;

class Solution {
 public:
  ll rlen, clen, n;
  set<pi> coords;
  map<char, pi> drs = {
      {'R', {0, 1}},
      {'L', {0, -1}},
      {'D', {1, 0}},
      {'U', {-1, 0}},
  };
  ll rmax = 0, rmin = 0, cmax = 0, cmin = 0;
  ll rDiff, cDiff;
  vector<string> grid;
  void run() {
    cin >> n;
    ll ans = 0;
    ll r = 0, c = 0;
    coords.insert({0, 0});
    for (ll i = 0; i < n; i++) {
      char d;
      ll val;
      string s;
      cin >> d >> val >> s;
      ll rAdd = drs[d].first;
      ll cAdd = drs[d].second;
      for (ll j = 0; j < val; j++) {
        r += rAdd;
        c += cAdd;
        coords.insert({r, c});
        rmax = max(rmax, r);
        rmin = min(rmin, r);
        cmax = max(cmax, c);
        cmin = min(cmin, c);
      }
    }
    rlen = rmax - rmin + 1;
    clen = cmax - cmin + 1;
    string rs(clen, '.');
    grid.resize(rlen, rs);
    for (auto x : coords) {
      grid[x.first - rmin][x.second - cmin] = '#';
    }
    dfs(0, 0);
    dfs(0, clen - 1);
    dfs(rlen - 1, 0);
    dfs(rlen - 1, clen - 1);
    for (auto &x : grid) {
      print(x);
      for (ll c = 0; c < clen; c++) {
        if (x[c] != ' ') ans++;
      }
    }
    print(ans);
  }
  void dfs(ll r, ll c) {
    if (r < 0 || r >= rlen || c < 0 || c >= clen || grid[r][c] != '.') return;
    grid[r][c] = ' ';
    for (auto &x : dirs) {
      dfs(r + x[0], c + x[1]);
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
