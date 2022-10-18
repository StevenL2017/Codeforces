#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v, T)            sort(v.begin(), v.end(), greater<T>())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

unordered_map<int, bool> memo;
vll nums;

bool dfs(int x) {
    if (x == 0) {
        return true;
    }
    if (memo.find(x) != memo.end()) {
        return memo[x];
    }

    bool ans = false;
    int n = (to_string(x)).size();
    repD(i, n, 1) {
        if (x >= nums[i] && dfs(x - nums[i])) {
            ans = true;
            break;
        }
    }
    memo[x] = ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    cout << (dfs(n) ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    nums = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};

    int t = 1;
    cin >> t;
    while (t--) solve();
}