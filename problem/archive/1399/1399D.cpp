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
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e6 + 3;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int k = 0;
    vi ans(n);
    deque<int> zero, one;
    rep(i, n) {
        if (s[i] == '0') {
            if (one.empty()) {
                k++;
                ans[i] = k;
                zero.push_back(k);
            } else {
                int cur = one.front();
                one.pop_front();
                ans[i] = cur;
                zero.push_back(cur);
            }
        } else {
            if (zero.empty()) {
                k++;
                ans[i] = k;
                one.push_back(k);
            } else {
                int cur = zero.front();
                zero.pop_front();
                ans[i] = cur;
                one.push_back(cur);
            }
        }
    }
    cout << k << endl;
    for (auto& x: ans) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}