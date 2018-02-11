// 分析：
// 最开始没有看到是排序链表，考虑采用哈希表，由于是排序链表，每次只用和
// 前一个节点进行比较即可。

// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (!head || !head->next)
			return head;
		ListNode *pre = head;
		ListNode *cur = head->next;
		while (cur)
		{
		    while (cur && pre->val == cur->val)
                cur = cur->next;
            pre->next = cur;
            pre = pre->next;
		}
		return head;
	}
};