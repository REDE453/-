#include <iostream>
#include <string>
using namespace std;
string CtoJ(string s) 
{
	string s1 = "";   //����һ���մ�
	for (int i = 0; i < s.size(); i++)   //����ԭ��
	{
		if (s[i] == '_')    //�������»��ߣ���������һ���ĳɴ�д��ĸ
			s[i + 1] -= 32;
		else            //����ֱ�ӽ��ַ������µ��ַ���
			s1.push_back(s[i]);
	}
	return s1;    //�������ַ���
}

int main()
{
	string s;
	while (cin >> s)
		cout << CtoJ(s) << endl;
	return 0;
}