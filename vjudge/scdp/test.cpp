#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double dp[1 << 22];
double p[22];
int main()
{
	int n;
	while (cin >> n)
	{
		double op = 0;
		for (int i = 0; i <n; i++)
		{
			scanf("%lf", &p[i]);
			op += p[i];
		}
		op = 1 - op;
		dp[(1 << n) - 1] = 0;
		for (int i = (1 << n) - 2; i >= 0; i--)
		{
			double x = 0, sum = 1;
			for (int j = 0; j < n;j++)
			if (i&(1 << j)) x += p[j];
			else            sum += p[j] * dp[i|(1 << j)];
			dp[i] = sum / (1 - op - x);
		}
		printf("%.5lf\n", dp[0]);
	}
}

