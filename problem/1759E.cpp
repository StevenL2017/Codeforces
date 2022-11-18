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

void solve() {
    ll n, h; cin >> n >> h;
    vector<ll> a(n); in(a);

    sorta(a);

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    ll tot = h;
    int g = 2, b = 1, i = 0;
    while (i < n) {
        if (tot > a[i]) {
            tot += a[i] / 2;
            cnt1++;
            i++;
        } else {
            if (g > 0) {
                tot *= 2;
                g--;
            }
            else if (b > 0) {
                tot *= 3;
                b--;
            }
            else {
                break;
            }
        }
    }

    tot = h;
    g = 2, b = 1, i = 0;
    while (i < n) {
        if (tot > a[i]) {
            tot += a[i] / 2;
            cnt2++;
            i++;
        } else {
            if (b > 0) {
                tot *= 3;
                b--;
            }
            else if (g > 0) {
                tot *= 2;
                g--;
            }
            else {
                break;
            }
        }
    }

    tot = h;
    g = 2, b = 1, i = 0;
    while (i < n) {
        if (tot > a[i]) {
            tot += a[i] / 2;
            cnt3++;
            i++;
        } else {
            if (g > 1) {
                tot *= 2;
                g--;
            }
            else if (b > 0) {
                tot *= 3;
                b--;
            }
            else if (g > 0) {
                tot *= 2;
                g--;
            }
            else {
                break;
            }
        }
    }

    cout << max({cnt1, cnt2, cnt3}) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}