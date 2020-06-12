//求和
//class Solution {
//public:
//	int Add(int num1, int num2)
//	{
//		int sum = num1 ^ num2;
//		int ret = (num1&num2) << 1;
//		if (0 != ret)
//		{
//			sum = Add(sum, ret);
//		}
//		return sum;
//	}
//};
//二叉树的镜像
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//class Solution {
//public:
//	void Mirror(TreeNode *pRoot) {
//		if (pRoot == NULL)
//			return;
//		TreeNode *temp = pRoot->left;
//		pRoot->left = pRoot->right;
//		pRoot->right = temp;
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//
//	}
//};