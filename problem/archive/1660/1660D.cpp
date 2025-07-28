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
    int n;
    cin >> n;
    vi a(n);
    in(a);

    vi ans(2);
    ans[1] = n;
    int mx = 0;
    for (int l = -1, r = 0; r <= n; r++) {
        if (r < n && a[r] != 0) {
            continue;
        }
        int cnt = 0, neg = 0;
        for (int i = l + 1; i < r; i++) {
            if (abs(a[i]) == 2) {
                cnt++;
            }
            if (a[i] < 0) {
                neg ^= 1;
            }
        }
        int left = l, right = r;
        if (neg) {
            int cl = 0;
            while (true) {
                if (abs(a[left + 1]) == 2) {
                    cl++;
                }
                left++;
                if (a[left] < 0) {
                    break;
                }
            }
            int cr = 0;
            while (true) {
                if (abs(a[right - 1]) == 2) {
                    cr++;
                }
                right--;
                if (a[right] < 0) {
                    break;
                }
            }
            if (cnt - cl > cnt - cr) {
                right = r;
                cnt -= cl;
            } else {
                left = l;
                cnt -= cr;
            }
        }
        if (cnt > mx) {
            mx = cnt;
            ans[0] = left + 1;
            ans[1] = n - right;
        }
        l = r;
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}