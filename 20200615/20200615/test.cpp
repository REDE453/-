public int lengthOfLongestSubstring(String s) {
	if (s == null || s.length() == 0) return 0;
	Map<Character, Integer> map = new HashMap<>();
	int start = 0;
	int result = 0;
	for (int i = 0; i < s.length(); i++) {
		if (map.containsKey(s.charAt(i))) {
			start = Math.max(map.get(s.charAt(i)) + 1, start); // ����ظ�λ�ô���start����Ҫ����start,��С������
		}
		map.put(s.charAt(i), i);
		result = Math.max(result, i - start + 1);
	}
	return result;
}