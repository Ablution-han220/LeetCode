/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (48.13%)
 * Likes:    14593
 * Dislikes: 542
 * Total Accepted:    1.4M
 * Total Submissions: 3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted
 * in ascending order.
 * 
 * Merge all the linked-lists into one sorted linked-list and return it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: lists = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: lists = [[]]
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length will not exceed 10^4.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 1. priority_queue time:O(kn×logk) space:O(k)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [&](ListNode* a, ListNode* b) {
            return a->val > b->val;   
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for (ListNode* headnode: lists) {
            if (headnode != nullptr) {
                q.emplace(headnode);
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy; 
        while (!q.empty()) {
            ListNode* node = q.top();
            q.pop();
            cur->next = node;
            cur = cur->next;
            node = node->next;
            if (node) {
                q.emplace(node);
            } 
        } 
        return dummy->next;
    }
};
// @lc code=end

