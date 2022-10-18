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
    int p, f, cnts, cntw, s, w;
    cin >> p >> f >> cnts >> cntw >> s >> w;

    int ans = 0;
    rep(i, min(cnts, p / s) + 1) {
        int cnt_ps = i;
        int cnt_pw = min(cntw, (p - cnt_ps * s) / w);

        int cnt_f = 0;
        int max_cnt_fs = min(cnts - cnt_ps, f / s);
        int max_cnt_fw = min(cntw - cnt_pw, f / w);
        cnt_f = max(cnt_f, max_cnt_fs + min(cntw - cnt_pw, (f - max_cnt_fs * s) / w));
        cnt_f = max(cnt_f, max_cnt_fw + min(cnts - cnt_ps, (f - max_cnt_fw * w) / s));

        ans = max(ans, cnt_ps + cnt_pw + cnt_f);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}