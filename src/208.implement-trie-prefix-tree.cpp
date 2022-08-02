/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
private:
    bool isEnd;
    vector<Trie*> next;
public:
    Trie(): next(26), isEnd(false) {
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char c: word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c: word) {
            if (node->next[c - 'a'] == nullptr) {
                return false;
            } else {
                node = node->next[c - 'a'];
            }
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c: prefix) {
            if (node->next[c - 'a'] == nullptr) {
                return false;
            } else {
                node = node->next[c - 'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

