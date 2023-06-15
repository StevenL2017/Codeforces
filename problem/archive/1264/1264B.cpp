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

void solve() {
    vi a(4); in(a);

    int tot = a[0] + a[1] + a[2] + a[3];

    for (int s = 0; s < 4; s++) {
        if (a[s] == 0) continue;
        vi ans, c = a;
        int last = s;
        ans.push_back(last);
        c[last]--;
        for (int i = 0; i < tot - 1; i++) {
            if (last && c[last - 1]) {
                last--;
                ans.push_back(last);
                c[last]--;
            }
            else if (last + 1 <= 3 && c[last + 1]) {
                last++;
                ans.push_back(last);
                c[last]--;
            }
            else {
                break;
            }
        }
        if (ssz(ans) == tot) {
            cout << "YES\n";
            out(ans);
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}