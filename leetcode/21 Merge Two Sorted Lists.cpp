#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode(0), *p1 = l1, *p2 = l2, *res = head;
	while (p1 && p2)
	{
		if (p1->val < p2->val)
		{
			res->next = p1;
			p1 = p1->next;
		}
		else
		{
			res->next = p2;
			p2 = p2->next;
		}
		res = res->next;
	}
	while (p1)
	{
		res->next = p1;
		p1 = p1->next;
		res = res->next;
	}
	while (p2)
	{
		res->next = p2;
		p2 = p2->next;
		res = res->next;
	}

	res = head->next;
	delete head;
	return res;
}

int main()
{
	ListNode* l1 = NULL;// = new ListNode(2);
	/*l1->next = new ListNode(4);
	l1->next->next = new ListNode(6);*/

	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(5);

	ListNode* res = mergeTwoLists(l1, l2);
	while (res)
	{
		printf("%d\n", res->val);
		res = res->next;
	}

	return 0;
}