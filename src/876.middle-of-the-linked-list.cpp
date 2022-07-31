/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        // (1) two pointer time:O(n) space:O(1)
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
        // (2) output to array time:O(n) space:O(n)
    //     vector<ListNode*> res;
    //     while (head != nullptr) {
    //         res.push_back(head);
    //         if (head->next == nullptr) {
    //             break;
    //         }
    //         head = head->next;
    //     }
    //     return res[res.size() / 2];
    // }
};
// @lc code=end

