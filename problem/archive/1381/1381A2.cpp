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
    int n; cin >> n;
    string a, b; cin >> a >> b;

    vi ans;
    int i = 0, j = n - 1, c = 0;
    repd(k, n - 1, -1) {
        if (c & 1) {
            if (a[j] == b[k]) {
                if (a[i] != b[k]) ans.push_back(1);
                ans.push_back(k + 1);
                swap(i, j);
                c++;
            }
        } else {
            if (a[j] != b[k]) {
                if (a[i] == b[k]) ans.push_back(1);
                ans.push_back(k + 1);
                swap(i, j);
                c++;
            }
        }
        if (i < j) j--;
        else j++;
    }

    cout << ssz(ans) << " ";
    out(ans);
    if (ans.empty()) cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}