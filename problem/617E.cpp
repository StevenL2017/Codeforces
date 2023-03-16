#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int BLOCK_SIZE = 316; // sqrt(1e5)

struct Q {
    int l, r, idx;
    bool operator < (const Q other) const {
        return r < other.r;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n); in(a);

    vi pre(n + 1, 0);
    rep(i, n) {
        pre[i + 1] = pre[i] ^ a[i];
    }

    vector<vector<Q>> blocks(n / BLOCK_SIZE + 2);
    rep(i, m) {
        int l, r; cin >> l >> r;
        l--; r++;
        blocks[l / BLOCK_SIZE].push_back(Q{l, r, i});
    }
    for (auto& b: blocks) {
        sorta(b);
    }

    vector<ll> ans(m);
    vi cnt(1 << 20, 0);
    ll res = 0;
    auto add = [&] (int v) {
        res += cnt[v ^ k];
        cnt[v]++;
    };
    auto del = [&] (int v) {
        cnt[v]--;
        res -= cnt[v ^ k];
    };
    rep(i, ssz(blocks)) {
        int left = i * BLOCK_SIZE, right = i * BLOCK_SIZE;
        for (auto& q: blocks[i]) {
            while (right < q.r) {
                add(pre[right]);
                right++;
            }
            while (left < q.l) {
                del(pre[left]);
                left++;
            }
            while (left > q.l) {
                left--;
                add(pre[left]);
            }
            ans[q.idx] = res;
        }
        repa(j, left, right) {
            del(pre[j]);
        }
    }

    rep(i, m) cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}