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

void solve() {
    ll n; cin >> n;

    vi digit, cnt(10, 0);
    while (n) {
        digit.push_back(n % 10);
        cnt[n % 10]++;
        n /= 10;
    }

    if (!(cnt[2] && cnt[5]) && !(cnt[7] && cnt[5]) && !(cnt[5] && cnt[0]) && !(cnt[0] > 1)) {
        cout << -1 << endl;
        return;
    }

    vi first(10, -1);
    rep(i, ssz(digit)) {
        if (first[digit[i]] == -1) {
            first[digit[i]] = i;
        }
    }

    auto calc = [&] (int f, int s) -> int {
        vi temp = digit;
        int cur = 0;
        repd(i, first[f], 0) {
            swap(temp[i], temp[i - 1]);
            cur++;
        }
        rep(i, ssz(temp)) {
            if (temp[i] == s) {
                repd(j, i, 1) {
                    swap(temp[j], temp[j - 1]);
                    cur++;
                }
                break;
            }
        }
        repd(i, ssz(temp) - 1, -1) {
            if (temp[i] == 0) continue;
            swap(temp[ssz(temp) - 1], temp[i]);
            cur += ssz(temp) - i - 1;
            break;
        }
        if (temp[0] == f && temp[1] == s) return cur;
        else return INT_MAX;
    };

    int ans = INT_MAX;
    // 00
    if (cnt[0] > 1) {
        int cur = 0, cnt = 0;
        rep(i, ssz(digit)) {
            if (digit[i] == 0) {
                cur += i - cnt;
                cnt++;
                if (cnt == 2) break;
            }
        }
        ans = min(ans, cur);
    }
    // 05
    if (cnt[5] && cnt[0]) {
        ans = min(ans, calc(0, 5));
    }
    // 57
    if (cnt[7] && cnt[5]) {
        ans = min(ans, calc(5, 7));
    }
    // 52
    if (cnt[2] && cnt[5]) {
        ans = min(ans, calc(5, 2));
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}