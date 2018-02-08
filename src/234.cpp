// 分析：
// 判断一个链表是否是回文链表。首先通过快慢指针找到链表的中点，在慢指针走的过程
// 中，将遍历结点加入到栈中，然后从中点开始遍历并分别弹栈比较，判断是否是回文。
// 这里主要需要考虑两个边界条件，链表元素只有2个和链表元素为偶数个的情况。
// 由于采用了栈，则空间复杂度不为O(1)。

//Given a singly linked list, determine if it is a palindrome.
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
    bool isPalindrome(ListNode* head) {
		if (!head)
			return true;
		bool result = true;
		ListNode *fast = head;
		ListNode *slow = head;
		stack<ListNode *> prev;
		while (fast->next && fast->next->next)
		{
			prev.push(slow);
			slow = slow->next;
			fast = fast->next->next;
		}
		if (prev.empty())
			prev.push(head);
		if (fast->next)
			prev.push(slow);
		ListNode *start = slow->next;
		while (start)
		{
			ListNode *node = prev.top();
			if (node->val != start->val)
			{
				result = false;
				break;
			}
			start = start->next;
			prev.pop();
		}
		return result;
    }
};