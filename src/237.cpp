// 分析：
// 由于没有给出链表的头结点，不能采用遍历链表的方式删除。这里考虑将删除结点的
// 后一结点复制给当前结点，并将当前结点的next指针指向next->next，将next结点删除
// 即可。

// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

// Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function

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
    void deleteNode(ListNode* node) {
        if (!node)
			return;
		if (!node->next)
		{
			delete node;
			return;
		}
		node->val = node->next->val;
		ListNode *nextnode = node->next;
		node->next = nextnode->next;
		delete nextnode;
    }
};