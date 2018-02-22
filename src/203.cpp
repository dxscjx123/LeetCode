// 分析：
// 由于需要考虑头结点是否是需要删除节点的情况，如果分支判断
// 比较麻烦，所以考虑设置一个dummy节点，其next指向头结点。

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
    ListNode* removeElements(ListNode* head, int val) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *curnode = dummy;
		while (curnode->next)
		{
			if (curnode->next->val == val)
				curnode->next = curnode->next->next;
			else
				curnode = curnode->next;
		}
		return dummy->next;
    }
};