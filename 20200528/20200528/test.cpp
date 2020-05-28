#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
	void insert(string str)
	{
		datasets[str] = 1;
		cout << "ok" << endl;
	}
	void search(string str)
	{
		if (datasets[str] == 1) {
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	void deletesol(string str)
	{
		datasets[str] = 0;
		cout << "ok" << endl;
	}
	void dealWith(string temp)
	{
		startWith = temp.find(':');
		selectWay = temp[startWith - 1];
		res = temp.substr(startWith + 1);
		if (selectWay == 'i')
		{
			insert(res);
		}
		else if (selectWay == 'd')
		{
			deletesol(res);
		}
		else
		{
			search(res);
		}
	}
private:
	char selectWay;
	int startWith;
	string res;
	unordered_map<string, int> datasets;
};
int main()
{
	string in;
	Solution sol;
	while (cin >> in)
	{
		if (in == "end") 
		{
			break;
		}
		sol.dealWith(in);

	}

}