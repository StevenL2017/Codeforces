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
    int m;
    cin >> m;
    ll x = 0;
    stack<ll> st;
    st.push(1);
    while (m--) {
        string s;
        cin >> s;
        if (s == "for") {
            int n;
            cin >> n;
            st.push(min(1ll << 32, st.top() * n));
        } else if (s == "add") {
            x += st.top();
        } else {
            st.pop();
        }
    }
    if (x < (1ll << 32)) cout << x << endl;
    else cout << "OVERFLOW!!!" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}