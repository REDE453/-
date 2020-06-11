class Solution {
private:
	map<char, string> mp = { {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
	vector<string> res;
	string temp;
public:
	void combine(string &digits, int start) {//»ØËÝ·¨
		if (start == digits.size()) {
			res.push_back(temp); return;
		}
		for (int i = 0; i < mp[digits[start]].size(); i++) {
			temp += mp[digits[start]][i];
			combine(digits, start + 1);
			temp.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		combine(digits, 0);
		return res;
	}
};