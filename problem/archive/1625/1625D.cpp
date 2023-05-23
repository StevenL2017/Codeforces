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

const int K = 31;

class Trie {
public:
    vector<Trie*> children;
    pair<int, int> v;

    Trie() : children(2), v({1, -1}) {}

    void insert(int val, pair<int, int> v) {
        Trie* node = this;
        for (int i = K; i >= 0; i--) {
            int bit = val >> i & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
            node->v = max(node->v, v);
        }
    }

    // 大于等于limit
    pair<int, int> query(int val, int limit) {
        pair<int, int> ans = {1, -1};
        Trie* node = this;
        for (int i = K; i >= 0; i--) {
            int bit = val >> i & 1;
            if (~limit >> i & 1) {
                if (node->children[bit ^ 1] != nullptr) {
                    ans = max(ans, node->children[bit ^ 1]->v);
                }
                if (node->children[bit] == nullptr) {
                    return ans;
                }
                node = node->children[bit];
            } else {
                if (node->children[bit ^ 1] == nullptr) {
                    return ans;
                }
                node = node->children[bit ^ 1];
            }
        }
        ans = max(ans, node->v); // 等于的情况
        return ans;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return a[i] < a[j]; });

    vector<pair<int, int>> f(n);
    Trie* tree = new Trie();
    for (int i = 0; i < n; i++) {
        int j = idx[i];
        f[i] = tree->query(a[j], k);
        auto cur = make_pair(f[i].first + 1, i);
        tree->v = max(tree->v, cur);
        tree->insert(a[j], cur);
    }

    int mx = max_element(f.begin(), f.end()) - f.begin();
    if (f[mx].first == 1) {
        cout << -1 << endl;
    } else {
        cout << f[mx].first << endl;
        int i = mx;
        while (i != -1) {
            cout << idx[i] + 1 << " ";
            i = f[i].second;
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}