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
    int n; cin >> n;
    vi a(n); in(a);

    int idx1 = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (idx1 == -1) {
                idx1 = i;
                break;
            }
        }
    }

    if (idx1 == -1) {
        cout << "NO\n";
        return;
    }
    
    vi st;
    int mx = n + 1;
    for (int i = 0; i < n; i++) {
        int j = (i + idx1) % n;
        while (!st.empty() && st.back() >= a[j]) {
            st.pop_back();
            mx++;
            if (mx > n) {
                cout << "NO\n";
                return;
            }
        }
        if (!st.empty() && st.back() + 1 < a[j]) {
            cout << "NO\n";
            return;
        }
        st.push_back(a[j]);
        mx--;
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}