class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == NULL && q == NULL)
			return true;
		queue<TreeNode*> q1, q2;
		q1.push(p); q2.push(q);
		TreeNode *tmp1, *tmp2;
		while (!q1.empty() && !q2.empty())
		{
			tmp1 = q1.front();
			tmp2 = q2.front();
			q1.pop(); q2.pop();
			if (tmp1 == NULL && tmp2 == NULL)
				continue;
			if (tmp1 == NULL || tmp2 == NULL)
				return false;
			if (tmp1->val != tmp2->val)
				return false;
			if (tmp1 != NULL)
			{
				q1.push(tmp1->left);
				q1.push(tmp1->right);
			}
			if (tmp2 != NULL)
			{
				q2.push(tmp2->left);
				q2.push(tmp2->right);
			}
		}
		if (!q1.empty() || !q2.empty())
			return false;
		return true;
	}
};