bool canJump(int A[], int n) {
	vector<bool> dp(n, false);
	dp[0] = true;
	for (int i = 0; i < n&&dp[i]; i++)
	{
		for (int j = 0; j <= A[i]; j++)
			dp[i + j] = true;
	}
	return dp[n - 1];
}