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
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)

void solve() {
    int n; cin >> n;
    vi a(n);
    bool ans = false;
    rep(i, n) {
        cin >> a[i];
        if (!ans) {
            if (a[i] == 0) {
                ans = true;
                continue;
            }
            rep(j, i) {
                if (a[j] == a[i]) {
                    ans = true;
                    break;
                }
            }
        }
    }

    if (ans) {
        cout << "YES" << endl;
        return;
    }

    function<bool(int, vi)> dfs = [&] (int mask, vi nums) -> bool {
        if (nums.size() == n) {
            int num;
            rep(i, n) {
                if (!(mask & (1 << i))) {
                    num = a[i];
                    break;
                }
            }
            rep(i, n) {
                rep(j, i) {
                    if (abs(nums[j] - nums[i]) == abs(num)) return true;
                }
            }
            return false;
        }

        rep(i, n) {
            int cur = 1 << i;
            if (mask & cur) continue;

            int nxt = nums.back() + a[i];
            nums.push_back(nxt);
            if (dfs(mask | cur, nums)) return true;
            nums.pop_back();

            nxt = nums.back() - a[i];
            nums.push_back(nxt);
            if (dfs(mask | cur, nums)) return true;
            nums.pop_back();
        }
        return false;
    };
    
    ans = dfs(0, {0});
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}