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
    string s; int k;
    cin >> s >> k;

    int n = ssz(s);
    vi cnt(10, 0);
    rep(i, n) cnt[s[i] - '0']++;

    int c = 0;
    rep(z, 10) {
        if (cnt[z] > 0) c++;
    }
    if (c <= k) {
        cout << s << endl;
        return;
    }

    repd(i, n - 1, -1) {
        cnt[s[i] - '0']--;
        repa(j, s[i] - '0' + 1, 10) {
            cnt[j]++;

            int c = 0, mn = 10;
            rep(z, 10) {
                if (cnt[z] > 0) c++, mn = min(mn, z);
            }
            if (c <= k) {
                if (c < k) mn = 0;
                s[i] = (char)(j + '0');
                repa(i0, i + 1, n) {
                    s[i0] = (char)(mn + '0');
                }
                cout << s << endl;
                return;
            }

            cnt[j]--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}