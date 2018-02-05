// 分析：
// 归并排序。首先需要找到链表的中间节点，然后从中间节点截成两段，分别递归排序，最后
// 将递归结果进行合并，先递归后合并（归并）。
// 这里需要注意一点，截成两段后，对前一段链表需要设置尾节点下一节点为空，否则在递归
// 中不能达到终止条件（fast = slow,fast->next = nullptr)

class Solution {
public:
	ListNode *mergesort(ListNode *l1, ListNode *l2)
	{
		ListNode dummy(-1);
		for (ListNode *p = &dummy; (l1 != nullptr) || (l2 != nullptr); p = p->next)
		{
			int val1 = (l1 == nullptr) ? INT_MAX : l1->val;
			int val2 = (l2 == nullptr) ? INT_MAX : l2->val;
			if (val1 <= val2)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
		}
		return dummy.next;
	}

    ListNode *sortList(ListNode *head) {
        if (!head || !(head->next))
			return head;

		ListNode *slow = head;
		ListNode *fast = head;
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		fast = slow;
		slow = slow->next;
		fast->next = nullptr;
		ListNode *l1 = sortList(head);
		ListNode *l2 = sortList(slow);
		return mergesort(l1, l2);
    }
};