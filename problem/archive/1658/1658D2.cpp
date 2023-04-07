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

class Trie {
private:
    int L;
    Trie* left;
    Trie* right;
    long long cnt;

public:
    Trie() : L(18), left(nullptr), right(nullptr), cnt(0) {}

    void insert(long long val) {
        Trie* node = this;
        for (int i = L; i >= 0; i--) {
            if (!(val >> i & 1)) {
                if (node->left == nullptr) {
                    node->left = new Trie();
                }
                node = node->left;
            } else {
                if (node->right == nullptr) {
                    node->right = new Trie();
                }
                node = node->right;
            }
            node->cnt++;
        }
    }

    long long query_maxor(long long val) {
        Trie* node = this;
        long long ans = 0;
        for (int i = L; i >= 0; i--) {
            if (node == nullptr) {
                return ans;
            }
            if (val >> i & 1) {
                if (node->left != nullptr) {
                    ans |= 1ll << i;
                    node = node->left;
                } else {
                    node = node->right;
                }
            } else {
                if (node->right != nullptr) {
                    ans |= 1ll << i;
                    node = node->right;
                } else {
                    node = node->left;
                }
            }
        }
        return ans;
    }

    long long query_cnt(long long val, long long limit) {
        // 严格小于limit的数对异或值数量
        Trie* node = this;
        long long ans = 0;
        for (int i = L; i >= 0; i--) {
            if (node == nullptr) {
                break;
            }
            auto cur = val >> i & 1;
            if (limit >> i & 1) {
                if (!cur && node->left != nullptr) {
                    ans += node->left->cnt;
                }
                if (cur && node->right != nullptr) {
                    ans += node->right->cnt;
                }
                if (cur) node = node->left;
                else node = node->right;
            } else {
                if (!cur) node = node->left;
                else node = node->right;
            }
        }
        return ans;
    }

    void remove(long long val) {
        Trie* node = this;
        for (int i = L; i >= 0; i--) {
            if (val >> i & 1) {
                node = node->right;
            } else {
                node = node->left;
            }
            node->cnt--;
        }
    }
};

void solve() {
    int l, r; cin >> l >> r;
    vi a(r - l + 1); in(a);

    Trie tree;
    rep(i, r - l + 1) {
        tree.insert(a[i]);
    }

    rep(i, r - l + 1) {
        int x = (a[i] ^ l);
        auto c = tree.query_cnt(x, r + 1) - tree.query_cnt(x, l);
        if (c == r - l + 1) {
            cout << x << endl;
            return;
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