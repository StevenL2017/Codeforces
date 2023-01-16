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
    int n, k; string s;
    cin >> n >> k >> s;

    if (n % k != 0) {
        cout << -1 << endl;
        return;
    }

    vi cnt(26, 0);
    rep(i, n) cnt[s[i] - 'a']++;

    bool ok = true;
    rep(i, 26) {
        if (cnt[i] % k != 0) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << s << endl;
        return;
    }

    repd(i, n - 1, -1) {
        cnt[s[i] - 'a']--;
        repa(j, s[i] - 'a' + 1, 26) {
            cnt[j]++;
            int tot = 0;
            rep(c, 26) {
                tot += (k - cnt[c] % k) % k;
            }
            if (tot <= n - 1 - i) {
                int cnt_a = n - 1 - i - tot;
                s[i] = (char)(j + 'a');
                repa(i0, i + 1, n) {
                    if (cnt_a) {
                        s[i0] = 'a';
                        cnt_a--;
                        continue;
                    }
                    rep(j0, 26) {
                        if (cnt[j0] % k != 0) {
                            cnt[j0]++;
                            s[i0] = (char)(j0 + 'a');
                            break;
                        }
                    }
                }
                cout << s << endl;
                return;
            }
            cnt[j]--;
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}