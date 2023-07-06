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
    int n, k, x;
    cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES\n";
        vi ans(n, 1);
        cout << ssz(ans) << endl;
        out(ans);
    } else {
        if (k == 1 || (n & 1) && k == 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            vi ans;
            while (n - 2 >= 2) {
                ans.push_back(2);
                n -= 2;
            }
            if (n) ans.push_back(n);
            cout << ssz(ans) << endl;
            out(ans);
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