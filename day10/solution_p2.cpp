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
#define tpp tuple<ll, ll, ll>
ll MOD = 1e9 + 7;
ll MX = 1e15;
/*
 | is a vertical pipe connecting north and south.
- is a horizontal pipe connecting east and west.
L is a 90-degree bend connecting north and east.
J is a 90-degree bend connecting north and west.
7 is a 90-degree bend connecting south and west.
F is a 90-degree bend connecting south and east.
. is ground; there is no pipe in this tile.
S is the starting position of the animal; there is a pipe on this tile, but your
sketch doesn't show what shape the pipe has.

 */
class Solution {
 public:
  ll n;
  map<char, vector<pi>> pipeMap = {
      {'|', {{-1, 0}, {1, 0}}}, {'-', {{0, -1}, {0, 1}}},
      {'L', {{-1, 0}, {0, 1}}}, {'J', {{-1, 0}, {0, -1}}},
      {'7', {{1, 0}, {0, -1}}}, {'F', {{1, 0}, {0, 1}}},
  };
  ll rlen, clen;
  vector<string> grid;
  vector<vector<ll>> dist;
  void run() {
    cin >> rlen >> clen;
    rlen = rlen * 2 + 1;
    clen = clen * 2 + 1;
    string filler(clen, '_');
    ll sr, sc;
    dist.resize(rlen, vector<ll>(clen, 0));
    grid.resize(rlen);
    for (ll r = 0; r < rlen; r++) {
      if (r % 2 == 0) {
        grid[r] = filler;
        continue;
      }
      string o;
      cin >> o;
      grid[r] = '_';
      for (ll c = 0; c < o.size(); c++) {
        grid[r] += o[c];
        grid[r] += '_';
      }
    }
    for (ll r = 0; r < rlen; r++)
      for (ll c = 0; c < clen; c++)
        if (grid[r][c] == 'S') {
          sr = r;
          sc = c;
        }

    print2(sr, sc);
    dist[sr][sc] = 1;
    auto x = dirs[1];
    dfs(sr + x[0] * 2, sc + x[1] * 2, {sr, sc});

    for (auto x : grid) print(x);
    print("");
    print("");
    print("");
    mark(0, 0);
    ll answer = 0;
    for (auto x : grid) {
      print(x);
      for (ll i = 0; i < clen; i++) {
        if (x[i] != '_' && x[i] != 'x') answer++;
      }
    }
    print(answer);

    return;
    ll res = 0;
    print(res);
  }

  void dfs(ll row, ll col, pi prev) {
    if (row < 0 || col < 0 || row >= rlen || col >= clen ||
        grid[row][col] == '.')
      return;
    fixBetween(prev, {row, col});
    if (grid[row][col] == 'S') {
      //            answer = max(answer, (dist[prev.first][prev.second] + 1)/2);
      //            print(answer);
      return;
    }
    auto ends = pipeMap[grid[row][col]];
    pi cod = {row, col};
    auto first = get(ends[0], cod);
    auto second = get(ends[1], cod);

    if (prev != first && prev != second) return;
    dist[row][col] = dist[prev.first][prev.second];
    grid[row][col] = 'x';
    auto nxt = (prev == first) ? second : first;
    dfs(nxt.first, nxt.second, cod);
  }
  pi get(pi ad, pi cod) {
    return {cod.first + ad.first * 2, cod.second + ad.second * 2};
  }
  void fixBetween(pi prev, pi cod) {
    if (prev.first != cod.first) {
      ll lo = min(prev.first, cod.first);
      grid[lo + 1][prev.second] = 'x';
    } else {
      ll lo = min(prev.second, cod.second);
      grid[prev.first][lo + 1] = 'x';
    }
  }
  void mark(ll row, ll col) {
    if (row < 0 || col < 0 || row >= rlen || col >= clen ||
        grid[row][col] == 'x')
      return;
    grid[row][col] = 'x';
    for (auto x : dirs) mark(row + x[0], col + x[1]);
  }
};

int main() {
  fastInputOutput();
  usefile();

  Solution sol;
  sol.run();

  return 0;
}
