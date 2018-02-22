// 分析：
// 反转链表，设置pre，cur和next节点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *nextnode = cur->next;
        while (cur)
        {
			cur->next = pre;
			pre = cur;
			if (!nextnode)
				break;
			cur = nextnode;
			nextnode = nextnode->next;
        }
        return cur;
    }
};

/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *nextnode = cur->next;
        while (nextnode)
        {
            cur->next = pre;
            pre = cur;
            cur = nextnode;
            nextnode = nextnode->next;
            if (!nextnode)
                cur->next = pre;
        }
        return cur;
    }
};
*/