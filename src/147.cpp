// 分析：
// 对链表进行插入排序。分析见代码注释。

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
    ListNode *insertionSortList(ListNode *head) {
		if (!head)
			return nullptr;
		ListNode *dummy = new ListNode(-1);
		while (head)
		{
			ListNode *cur = dummy;
			ListNode *save = head->next;   //这里主要用于之后对head节点进行了更改
			while (cur->next != nullptr && cur->next->val < head->val)
				cur = cur->next;
			ListNode *tmp = cur->next;
			cur->next = head;
			cur->next->next = tmp;   //这里对head->next进行了更改
			head = save;   //需要重置head
		}
		return dummy->next;
    }
};