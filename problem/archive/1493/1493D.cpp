#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
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
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

const int MAXN = 2e5 + 3;

int nxt_prime[MAXN]; // next prime factor

void eratosthenes_nxt(int n) {
    for (int i = 2; i < n; i++) {
        if (nxt_prime[i] == 0) {
            nxt_prime[i] = i;
            if (i > 10000) continue;
            for (int j = i * i; j < n; j += i) {
                if (nxt_prime[j] == 0) {
                    nxt_prime[j] = i;
                }
            }
        }
    }
}

multiset<int> cnt[MAXN];
map<int, int> cnt_factor[MAXN];

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); in(a);

    eratosthenes_nxt(MAXN);

    ll g = 1;

    auto update = [&] (int i, int x) {
        while (x != 1) {
            int k = nxt_prime[x], c = 0;
            while (k == nxt_prime[x]) {
                c++;
                x /= nxt_prime[x];
            }

            auto pre_c = cnt_factor[i][k];
            cnt_factor[i][k] += c;
            
            int pre_mn = 0;
            if (ssz(cnt[k]) == n) {
                pre_mn = (*cnt[k].begin());
            }

            if (pre_c != 0) {
                cnt[k].erase(cnt[k].find(pre_c));
            }
            cnt[k].insert(pre_c + c);

            if (ssz(cnt[k]) == n) {
                repa(j, pre_mn, (*cnt[k].begin())) {
                    g *= 1ll * k;
                    g %= MOD;
                }
            }
        }
    };

    rep(i, n) {
        update(i + 1, a[i]);
    }

    while (q--) {
        int i, x; cin >> i >> x;

        update(i, x);

        cout << g << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}