#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

int main(void) {
	int num;
	char c;
	vector<int> v;
	while (scanf_s("%d%c", &num, &c) && c != '\n') {
		v.push_back(num);
	}
	v.push_back(num);
	ListNode *head, *p, *q;
	head = nullptr;
	q = nullptr;
	//建立链表
	for (int i = 0; i < v.size(); i++) {
		p = new ListNode;
		p->next = nullptr;
		p->val = v[i];
		if (head == nullptr)
			head = p;
		else
			q->next = p;
		q = p;
	}

	//分割链表 前一部分 以及后一部分 利用快慢指针，奇数则前一部分比后一部分多一个数。
	ListNode *slow, *fast;
	slow = fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode *head1 = slow->next;
	slow->next = nullptr;
	//逆置后一部分链表
	ListNode *newhead = new ListNode;
	newhead->next = nullptr;
	ListNode *r = newhead;
	while (head1) {
		q = head1->next;
		head1->next = r->next;
		r->next = head1;
		head1 = q;
	}

	//交叉连接链表 L1 L2分别为两链表表头
	ListNode *L1 = head;
	ListNode *L2 = r->next;

	while (L2) {
		p = L1->next;
		q = L2->next;
		L1->next = L2;
		L2->next = p;
		L2 = q;
		L1 = p;
	}
	while (head->next) {
		cout << head->val << ",";
		head = head->next;
	}
	cout << head->val << endl;
	system("pause");
	return 0;
}