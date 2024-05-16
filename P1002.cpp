#include<iostream>
#include<vector>
using namespace std;

int x[] = { 0, 1, 1, 2, 2,-1,-1,-2,-2 };
int y[] = { 0, 2,-2, 1,-1, 2,-2, 1,-1 };

long long f(int x0, int y0, int m, int n)
{
	vector<vector<long long>> dp(m + 2, vector<long long>(n + 2, 0));
	bool is_die = false;
	int die_of_i =  m + 2, die_of_j = n + 2;

	for (int i = 1; i < m + 2; i++) {
		for (int j = 1; j < n + 2; j++) {

			is_die = false;
			for (int k = 0; k < 9; k++) {
				if (i == x0 + 1 + x[k] && j == y0 + 1 + y[k]) {
					dp[i][j] = 0;
					is_die = true;
					if (i == 1) {
						die_of_j = j;
					}
					if (j == 1) {
						die_of_i = i;
					}
					break;
				}
			}
			if (is_die) {
				continue;
			}
			
			if ((i == 1 || j == 1)&& i < die_of_i && j< die_of_j ) {
				dp[i][j] = 1;
				
				continue;
			}
			else if(i == 1 || j == 1){
				dp[i][j] = 0;
			}
			

			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m + 1][n + 1];

}


int main() {
	int x0, y0,m,n;
	cin >>  m >> n >> x0 >> y0;
	

	cout << f( x0, y0, m, n);
	return 0;

}