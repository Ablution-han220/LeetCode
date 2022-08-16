/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
// class Solution {
// public:
//     unordered_set<string> visit;
//     unordered_map<string, vector<string>> adjacent;
    
//     void dfs(vector<string>& merge, string& email) {
//         visit.insert(email);
//         merge.emplace_back(email);
        
//         for (string& neighbor: adjacent[email]) {
//             if (visit.find(neighbor) == visit.end()) {
//                 dfs(merge, neighbor);
//             }
//         }
//     }
    
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//         // (1) dfs time:O(NKlogNK) space:O(NK) where N is the number of accounts and KK is the maximum length of an account.
//         // create adjacent list
//         for (vector<string>& ac: accounts) {
//             string accountFirstEmail = ac[1];
//             for (int i = 2; i < ac.size(); ++i) {
//                 string email = ac[i];
//                 adjacent[accountFirstEmail].emplace_back(email);
//                 adjacent[email].emplace_back(accountFirstEmail);
//             }
//         }
        
//         vector<vector<string>> res;
//         for (vector<string> & ac: accounts) {
//             string accountName = ac[0];
//             string accountFirstEmail = ac[1];
            
//             if (visit.find(accountFirstEmail) == visit.end()) {
//                 vector<string> merge;
//                 merge.emplace_back(accountName);
//                 dfs(merge, accountFirstEmail);
                
//                 sort(merge.begin() + 1, merge.end());
//                 res.emplace_back(merge);
//             }
//         }
//         return res;
//     } 
// };

        // (2) Disjoint Set Union (DSU)
class DSU {
public:
    vector<int> root;
    vector<int> rank;
    
    DSU(int n): root(n), rank(n) {
        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
    }
    
    int findRoot(int x) {
        if (x != root[x]) {
            root[x] = findRoot(root[x]);
        }
        return root[x];
    }
    
    void merge(int x, int y) {
        int rootx = findRoot(x);
        int rooty = findRoot(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            root[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) {
                ++rank[rootx];
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        DSU dsu(accounts.size());
        
        unordered_map<string, int> emailGroup;
        for (int i = 0; i < accounts.size(); ++i) {
            // string accountName = accounts[i][0];
            int accountSize = accounts[i].size();
            for (int j = 1; j < accountSize; ++j) {
                string email = accounts[i][j];
                if (emailGroup.find(email) == emailGroup.end()) {
                    emailGroup[email] = i;
                } else {
                    dsu.merge(emailGroup[email], i);
                }
            }
        }
        
        unordered_map<int, vector<string>> components;
        for (auto& it: emailGroup) {
            string email = it.first;
            int group = it.second;
            components[dsu.findRoot(group)].emplace_back(email);
        }
        
        for (auto& it: components) {
            sort(it.second.begin(),it.second.end());
            int group = it.first;
            vector<string> tmp;
            string name = accounts[group][0];
            tmp.emplace_back(name);
            tmp.insert(tmp.end(), it.second.begin(),it.second.end());
            res.emplace_back(tmp);
        }
        return res;
    }
};
// @lc code=end

