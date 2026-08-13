class Solution {

private:
struct Node {
    char lc, rc;      // Leftmost and rightmost characters of the segment
    int prefix_len;   // Longest repeating character prefix
    int suffix_len;   // Longest repeating character suffix
    int max_len;      // Longest repeating character substring
};
    vector<Node> tree;

    // Helper function to merge two adjacent segment tree nodes
    Node merge(const Node& left, const Node& right, int left_len, int right_len) {
        Node parent;
        parent.lc = left.lc;
        parent.rc = right.rc;

        // Prefix length calculation
        parent.prefix_len = left.prefix_len;
        if (left.prefix_len == left_len && left.rc == right.lc) {
            parent.prefix_len += right.prefix_len;
        }

        // Suffix length calculation
        parent.suffix_len = right.suffix_len;
        if (right.suffix_len == right_len && left.rc == right.lc) {
            parent.suffix_len += left.suffix_len;
        }

        // Max length calculation
        parent.max_len = max(left.max_len, right.max_len);
        if (left.rc == right.lc) {
            parent.max_len = max(parent.max_len, left.suffix_len + right.prefix_len);
        }

        return parent;
    }

    void build(int node, int l, int r, const string& s) {
        if (l == r) {
            tree[node] = {s[l], s[l], 1, 1, 1};
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);
        
        int left_len = mid - l + 1;
        int right_len = r - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], left_len, right_len);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            tree[node] = {ch, ch, 1, 1, 1};
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, r, idx, ch);
        }

        int left_len = mid - l + 1;
        int right_len = r - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], left_len, right_len);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        
        tree.resize(4 * n);
        build(1, 0, n - 1, s);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len; // Root node always holds the overall max length
        }

        return ans;
    }
};