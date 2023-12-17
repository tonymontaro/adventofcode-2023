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
  ll answer = 0;
  vector<vector<ll>> dp;
  void run() {
    ll n;
    cin >> n;
    for (ll _ = 0; _ < n; _++) {
      string s;
      cin >> s;
      ll m;
      cin >> m;
      vector<ll> nums(m);
      for (ll i = 0; i < m; i++) cin >> nums[i];
      dp.clear();
      dp.resize(s.size() + 1, vector<ll>(nums.size() + 1, -1));
      //            print(s);
      //            printArr(nums);
      ll res = solve(s, nums, 0, 0);
      answer += res;

      //            print2(s, res);
    }
    print(answer);
  }
  ll solve(string &s, vector<ll> &nums, ll sIdx, ll idx) {
    ll n = s.size();
    ll m = nums.size();
    if (idx >= m) {
      if (sIdx >= n) return 1;
      if (s[sIdx] == '#') return 0;
      dp[sIdx][idx] = solve(s, nums, sIdx + 1, idx);
      return dp[sIdx][idx];
    }
    if (sIdx >= n) return 0;
    if (dp[sIdx][idx] != -1) return dp[sIdx][idx];
    if (s[sIdx] == '.') {
      dp[sIdx][idx] = solve(s, nums, sIdx + 1, idx);
      return dp[sIdx][idx];
    }

    ll last = sIdx + nums[idx];
    if (last - 1 >= n) {
      dp[sIdx][idx] = 0;
      return 0;
    }
    ll res = s[sIdx] == '?' ? solve(s, nums, sIdx + 1, idx) : 0;
    if ((last < n && s[last] == '#')) {
      dp[sIdx][idx] = res;
      return res;
    }

    for (ll i = sIdx; i < (sIdx + nums[idx]); i++) {
      if (s[i] == '.') return res;
    }
    ll rest = solve(s, nums, last + 1, idx + 1);
    dp[sIdx][idx] = res + rest;
    return res + rest;
  }
};
// 7601 too high
// 7047

int main() {
  fastInputOutput();
  usefile();

  Solution sol;
  sol.run();

  return 0;
}
