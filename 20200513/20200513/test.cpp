#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <limits.h>
#include <cstdio>
using namespace std;

struct Item {
	int a, b, x, y, state;
	Item() {
		state = 0;
	}

	void crot() {
		state = (state + 1) % 4;
		int dx = a - x, dy = b - y;
		a = x - dy;
		b = y + dx;
	}

	void input() {
		cin >> a >> b >> x >> y;
		state = 0;
	}

	bool operator ==(const Item &item2) {
		return a == item2.a && b == item2.b;
	}

	Item operator +(const Item &it2) {
		Item res;
		res.a = a + it2.a;
		res.b = b + it2.b;
		return res;
	}

	Item operator -(const Item &it2) {
		Item res;
		res.a = a - it2.a;
		res.b = b - it2.b;
		return res;
	}

	static bool ortho(const Item &it1, const Item &it2) {
		if (it1.a == 0 && it1.b == 0) return 0;
		if (it2.a == 0 && it2.b == 0) return 0;
		return it1.a * it2.a + it1.b * it2.b == 0;
	}
};

struct Pack {
	vector<Item> itemList;
	vector<Item*> itp;
	int step;

	Pack() {
		itemList = vector<Item>(4);
		itp = vector<Item*>(4, nullptr);
		for (int i = 0; i < 4; ++i) itp[i] = &itemList[i];
		step = INT_MAX;
	}

	void input() {
		for (int i = 0; i < 4; ++i)
			itemList[i].input();
		step = INT_MAX;
	}

	bool isSqaure() {
		for (int i = 1; i < 4; ++i) {
			if (i != 1) swap(itp[i], itp[1]);
			if (*itp[0] == *itp[1] || *itp[2] == *itp[3]) return 0;
			if (!(*itp[0] + *itp[1] == *itp[2] + *itp[3])) continue;
			if (!Item::ortho(*itp[0] - *itp[1], *itp[2] - *itp[3])) continue;
			if (Item::ortho(*itp[0] - *itp[2], *itp[0] - *itp[3])) return 1;
		}
		return 0;
	}

	void trySqaure(int rot_idx) {
		for (int i = 0; i < 4; ++i) {
			if (rot_idx == 0 && isSqaure()) {
				int tmp_step = 0;
				for (int j = 0; j < 4; ++j) tmp_step += itemList[j].state;
				if (step > tmp_step) step = tmp_step;
			}
			if (rot_idx > 0) trySqaure(rot_idx - 1);
			itemList[rot_idx].crot();
		}
	}
};

int main()
{
	int n;
	cin >> n;
	Pack eRoom;
	for (int i = 0; i < n; ++i) {
		eRoom.input();
		eRoom.trySqaure(3);
		cout << (eRoom.step > 16 ? -1 : eRoom.step) << endl;
	}
}