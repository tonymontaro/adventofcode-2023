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
  void run() {
    ll lnNums;
    cin >> lnNums;
    vector<pi> nums;
    for (ll i = 0; i < lnNums / 2; i++) {
      ll start;
      ll rang;
      cin >> start >> rang;
      ll end = start + rang - 1;
      nums.push_back({start, end});
    }
    update(nums);
    //        printArr(nums);
    ll lnMaps;
    cin >> lnMaps;
    vector<vector<tpp>> arr;
    for (ll _ = 0; _ < lnMaps; _++) {
      ll n;
      cin >> n;
      vector<pi> hold;
      for (ll i = 0; i < n; i++) {
        ll mStart, start, diff;
        cin >> mStart >> start >> diff;
        //                print3(start, diff, mStart);
        ll end = start + diff - 1;
        vector<pi> nw;
        for (auto x : nums) {
          if (start > x.second || end < x.first) {
            nw.push_back(x);
            continue;
          }
          ll uStart = max(start, x.first);
          ll uEnd = min(end, x.second);
          if (x.first <= uStart - 1) nw.push_back({x.first, uStart - 1});
          if (uEnd + 1 <= x.second) nw.push_back({uEnd + 1, x.second});
          diff = start - mStart;
          hold.push_back({uStart - diff, uEnd - diff});
        }
        swap(nw, nums);
      }
      for (auto x : hold) nums.push_back(x);
      update(nums);
    }
    print(nums[0].first);
  }
  void update(vector<pi> &nums) {
    sort(nums.begin(), nums.end());
    vector<pi> tNums;
    for (ll i = 0; i < nums.size(); i++) {
      auto num = nums[i];
      if (num.first > num.second) continue;
      if (tNums.empty()) {
        tNums.push_back(num);
        continue;
      }
      if (num.first > tNums.back().second) {
        tNums.push_back(num);
        continue;
      }
      tNums.back().second = max(tNums.back().second, num.second);
    }
    swap(nums, tNums);
  }
};

int main() {
  fastInputOutput();
  usefile();

  Solution sol;
  sol.run();

  return 0;
}
