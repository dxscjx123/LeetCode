// 分析：
// 判断一个链表是否是回文链表。首先通过快慢指针找到链表的中点，在慢指针走的过程
// 中，将遍历结点加入到栈中，然后从中点开始遍历并分别弹栈比较，判断是否是回文。
// 这里主要需要考虑两个边界条件，链表元素只有2个和链表元素为偶数个的情况。
// 由于采用了栈，则空间复杂度不为O(1)。

// 对于采用O(1)复杂度的方法，首先通过快慢指针找到中间结点，然后对链表后半段进行反
// 转，然后将反转的后半段与前半段比较。见注释。

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

//方法二
/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;
		bool result = true;
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast->next && fast->next->next) //快慢指针找到中点
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *middle = slow->next;
		
		ListNode *prev_node = nullptr;   //反转后半部分链表
		ListNode *cur_node = middle;
		ListNode *next_node = middle->next;
		while (next_node)
		{
			cur_node->next = prev_node;
			prev_node = cur_node;
			cur_node = next_node;
			next_node = next_node->next;
			if (next_node == nullptr)
				cur_node->next = prev_node;
		//当next为空，表示curnode为尾结点，设置curnode的next指针，这一点非常
		重要。因为curnode原来的next指向空，现在需要将其指向prev。
		}
		ListNode *behind_half = cur_node;
		
		ListNode *p = head;
		ListNode *q = behind_half;
		while (p && q)   //遍历前半部和后半部结点。
		{
			if (p->val != q->val)
			{
				result = false;
				break;
			}
			p = p->next;
			q = q->next;
		}
		
		return result;
    }
};
*/