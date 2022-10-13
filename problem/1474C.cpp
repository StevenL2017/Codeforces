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
    cin >> n;
    vi a(2 * n);
    rep(i, 2 * n) cin >> a[i];

    sortA(a);
    int x = 0;
    map<int, int> cnt;
    vector<pair<int, int>> ans;
    rep(i, 2 * n - 1) {
        rep(j, 2 * n - 1) {
            if (j == i) continue;
            cnt[a[j]]++;
        }

        x = a[i] + a.back();
        ans.emplace_back(a[i], a.back());

        bool valid = true;
        int j = 2 * n - 2, c = 2 * n - 2, y = a.back();
        while (j > 0 && c > 0) {
            if (j == i) {
                j--;
                continue;
            }

            cnt[a[j]]--;
            int other = y - a[j];
            if (cnt.find(other) == cnt.end() || cnt[other] == 0) {
                valid = false;
                break;
            }
            ans.emplace_back(other, a[j]);
            y = max(a[j], other);
            cnt[other]--;
            c -= 2;
            while (j == i || (j >= 0 && cnt[a[j]] == 0)) j--;
        }

        if (valid) {
            cout << "YES" << endl;
            cout << x << endl;
            for (auto& nums: ans) {
                cout << nums.first << " " << nums.second << endl;
            }
            return;
        }

        cnt.clear();
        ans.clear();
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}