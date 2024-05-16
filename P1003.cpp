#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
struct dt
{
	int x;
	int y;
	int a;
	int b;
}all[10005];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> all[i].x >> all[i].y >> all[i].a >> all[i].b;
	}
	int x, y;
	cin >> x >> y;

	int count = -1;
	for (int i = 0; i < n; i++) {
		if (x >= all[i].x && x <= all[i].x + all[i].a && y >= all[i].y && y <= all[i].y + all[i].b)
		{
			count = i + 1;

		}
		
	}

	cout << count;
	

	return 0;
}