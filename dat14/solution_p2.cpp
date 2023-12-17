#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;

void fastInputOutput() { cin.tie(nullptr)->sync_with_stdio(false); }

#define usefile()                                                     \
  ifstream cin("../test_input.txt"); /*ofstream cout("../out.txt");*/ \
  std::cin.rdbuf(cin.rdbuf());                                        \
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
#define tpp tuple<ll, ll, ll>
ll MOD = 1e9 + 7;
ll MX = 1e15;

class Solution {
 public:
  ll rlen, clen;
  ll idx = 0;
  map<string, ll> seen;
  vector<ll> results;
  vector<ll> cycle;
  void run() {
    cin >> rlen >> clen;
    vector<string> grid;
    grid.resize(rlen);
    vector<ll> cols(clen, 0);
    for (ll r = 0; r < rlen; r++) {
      string s;
      cin >> grid[r];
    }
    while (rotate(grid)) {
    }
    print(results.size());
    printArr(results);
    print(cycle.size());
    printArr(cycle);
    ll res = 1000000000 - results.size() - 1;
    ll n = cycle.size();
    print(cycle[res % n]);
  }
  bool rotate(vector<string> &grid) {
    goNorth(grid);
    goWest(grid);
    goSouth(grid);
    goEast(grid);
    string s;
    for (auto &x : grid) s += x;
    if (seen.find(s) != seen.end()) {
      print(seen[s]);
      for (ll i = seen[s]; i < idx; i++) cycle.push_back(results[i]);
      return false;
    }
    seen[s] = idx++;
    results.push_back(calculate(grid));
    return true;
  }
  void goNorth(vector<string> &grid) {
    vector<ll> cols(clen, 0);
    for (ll r = 0; r < rlen; r++) {
      for (ll c = 0; c < clen; c++) {
        if (grid[r][c] == '#') {
          cols[c] = r + 1;
          continue;
        }
        if (grid[r][c] == '.') continue;
        grid[r][c] = '.';
        grid[cols[c]][c] = 'O';
        cols[c]++;
      }
    }
  }
  void goSouth(vector<string> &grid) {
    vector<ll> cols(clen, rlen - 1);
    for (ll r = rlen - 1; r >= 0; r--) {
      for (ll c = 0; c < clen; c++) {
        if (grid[r][c] == '#') {
          cols[c] = r - 1;
          continue;
        }
        if (grid[r][c] == '.') continue;
        grid[r][c] = '.';
        grid[cols[c]][c] = 'O';
        cols[c]--;
      }
    }
  }
  void goWest(vector<string> &grid) {
    vector<ll> rows(rlen, 0);
    for (ll c = 0; c < clen; c++) {
      for (ll r = 0; r < rlen; r++) {
        if (grid[r][c] == '#') {
          rows[r] = c + 1;
          continue;
        }
        if (grid[r][c] == '.') continue;
        grid[r][c] = '.';
        grid[r][rows[r]] = 'O';
        rows[r]++;
      }
    }
  }
  void goEast(vector<string> &grid) {
    vector<ll> rows(rlen, clen - 1);
    for (ll c = clen - 1; c >= 0; c--) {
      for (ll r = 0; r < rlen; r++) {
        if (grid[r][c] == '#') {
          rows[r] = c - 1;
          continue;
        }
        if (grid[r][c] == '.') continue;
        grid[r][c] = '.';
        grid[r][rows[r]] = 'O';
        rows[r]--;
      }
    }
  }
  ll calculate(vector<string> &grid) {
    ll res = 0;
    for (ll r = 0; r < rlen; r++) {
      for (ll c = 0; c < clen; c++) {
        if (grid[r][c] == 'O') res += rlen - r;
      }
    }
    return res;
  }
};

int main() {
  fastInputOutput();
  usefile();

  Solution sol;
  sol.run();

  return 0;
}
