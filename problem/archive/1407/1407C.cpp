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

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;

    if (n == 1) {
        cout << "! 1" << endl;
        cout.flush();
        return;
    }

    vi ans(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i);
    }
    while (ssz(q) > 1) {
        int first = q.front(); q.pop();
        int second = q.front(); q.pop();
        int x1 = query(first + 1, second + 1);
        int x2 = query(second + 1, first + 1);
        if (x1 > x2) {
            ans[first] = x1;
            q.push(second);
        } else {
            ans[second] = x2;
            q.push(first);
        }
    }
    ans[q.front()] = n;

    cout << "! ";
    out(ans);
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}