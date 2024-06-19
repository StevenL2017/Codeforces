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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

bool check(string s, int x) {
    int n = ssz(s);
    if (n == x) return true;
    string s1, s2;
    map<string, int> cnt;
    for (int i = 0; i < n; i += x) {
        string cur = s.substr(i, x);
        if (s1.empty()) {
            s1 = cur;
        } else if (s2.empty() && cur != s1) {
            s2 = cur;
            int c = 0;
            for (int j = 0; j < x; j++) {
                if (s1[j] != s2[j]) {
                    c++;
                    if (c > 1) return false;
                }
            }
        }
        cnt[cur]++;
        if (ssz(cnt) > 2) return false;
    }
    if (!s2.empty() && cnt[s1] > 1 && cnt[s2] > 1) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = n, x = 1;
    while (x * x <= n) {
        if (n % x) {
            x++;
            continue;
        }
        if (check(s, x)) {
            ans = min(ans, x);
            break;
        }
        if (check(s, n / x)) {
            ans = min(ans, n / x);
        }
        x++;
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