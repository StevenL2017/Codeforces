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
    int n, k;
    cin >> n >> k;

    string ans(n, 'a');
    int i = 0;
    while (i < n) {
        for (int j = 0; j < k; j++) {
            ans[i++] = j + 'a';
            if (i == n) {
                cout << ans << endl;
                return;
            }
            for (int c = j + 1; c < k; c++) {
                ans[i++] = j + 'a';
                if (i == n) {
                    cout << ans << endl;
                    return;
                }
                ans[i++] = c + 'a';
                if (i == n) {
                    cout << ans << endl;
                    return;
                }
            }
        }
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