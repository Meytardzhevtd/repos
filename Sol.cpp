//#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include "optimization.h"

using namespace std;

pair<int, int> NULL_PAIR(0, 0);
const int MAX_LEN = 299993;
const int r = 153421;
vector<pair<int, int>> arr(MAX_LEN, NULL_PAIR);

int index(int x) {
	int i = (x * r) % MAX_LEN;
	while (arr[i].first != x && arr[i].first != 0) {
		++i;
		if (i == MAX_LEN)
			i = 0;
	}
	return i;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a, b, key_a, key_b;
	//cin >> n;
	n = readInt();
	for (int i = 0; i < n; ++i) {
		//cin >> a >> b;
		a = readInt();
		b = readInt();
		key_a = index(a);
		if (arr[key_a].first == 0) {
			arr[key_a].first = a;
			arr[key_a].second = a;
		}
		key_b = index(b);
		if (arr[key_b].first == 0) {
			arr[key_b].first = b;
			arr[key_b].second = b;
		}
		

		writeInt(abs(arr[key_a].second - arr[key_b].second), '\n');
		swap(arr[key_a].second, arr[key_b].second);
	}


	return 0;
}