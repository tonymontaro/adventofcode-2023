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
// #define tpp tuple<ll, ll, ll>
#define tpp tuple<ll, ll, ll, ll, ll>
ll MOD = 1e9 + 7;
ll MX = 1e15;

class Solution {
 public:
  ll rlen, clen;
  vector<string> grid;
  ll MX = 1e9;
  map<string, ll> seen;
  vector<pair<pi, vector<ll>>> directions = {
      // {move, otherDirs}
      {{0, 1}, {2, 3}},   // left
      {{0, -1}, {2, 3}},  // right
      {{1, 0}, {0, 1}},   // down
      {{-1, 0}, {0, 1}},  // up
  };
  void run() {
    cin >> rlen >> clen;
    grid.resize(rlen);
    for (ll r = 0; r < rlen; r++) {
      cin >> grid[r];
    }
    main(0, 0, 0, 0);
  }
  void main(ll srow, ll scol, ll direction, ll consecutive = 0) {
    seen.clear();
    priority_queue<tpp, vector<tpp>, greater<>> pq;
    ll res, row, col, dr, cs;
    seen[stringify({srow, scol, direction, consecutive})] = 0;
    pq.push({0, srow, scol, direction, consecutive});
    while (!pq.empty()) {
      tie(res, row, col, dr, cs) = pq.top();
      pq.pop();
      if (row < 0 || row >= rlen || col < 0 || col >= clen) continue;
      res += grid[row][col] - '0';
      if (row == rlen - 1 && col == clen - 1) {
        if (cs < 4) continue;
        print(res - (grid[0][0] - '0'));
        return;
      }
      if (cs < 10) {
        string s = stringify({row + directions[dr].first.first,
                              col + directions[dr].first.second, dr, cs + 1});
        if (seen.find(s) == seen.end() || (seen[s] > res)) {
          seen[s] = res;
          pq.push({res, row + directions[dr].first.first,
                   col + directions[dr].first.second, dr, cs + 1});
        }
      }
      if (cs < 4) continue;
      for (auto &nDir : directions[dr].second) {
        ll r = row + directions[nDir].first.first;
        ll c = col + directions[nDir].first.second;
        string s = stringify({r, c, nDir, 1});
        if (seen.find(s) == seen.end() || seen[s] > res) {
          seen[s] = res;
          pq.push({res, r, c, nDir, 1});
        }
      }
    }
  }

  string stringify(vector<ll> arr) {
    string res;
    for (auto x : arr) {
      res += to_string(x);
      res += ',';
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
