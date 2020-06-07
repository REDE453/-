public class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		if (l1 == null)
			return l2;
		if (l2 == null)
			return l1;
		ListNode head = new ListNode(0);
		ListNode p = head;

		int temp = 0;
		while (l1 != null || l2 != null || temp != 0) {
			if (l1 != null) {
				temp += l1.val;
				l1 = l1.next;
			}
			if (l2 != null) {
				temp += l2.val;
				l2 = l2.next;
			}

			p.next = new ListNode(temp % 10);
			p = p.next;
			temp /= 10;
		}
		return head.next;
	}
}