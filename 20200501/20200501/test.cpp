#include <iostream>
#include <string>
using namespace std;
string CtoJ(string s) 
{
	string s1 = "";   //定义一个空串
	for (int i = 0; i < s.size(); i++)   //遍历原串
	{
		if (s[i] == '_')    //若碰到下划线，则将它的下一个改成大写字母
			s[i + 1] -= 32;
		else            //否则直接将字符放入新的字符串
			s1.push_back(s[i]);
	}
	return s1;    //返回新字符串
}

int main()
{
	string s;
	while (cin >> s)
		cout << CtoJ(s) << endl;
	return 0;
}