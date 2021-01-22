/*
 * An implementation of Kontsevich-Manin recursion for n_d
 * which counts the number of genus 0, degree d curves in P^2
 * passing through prescribed 3d-1 'general' points.
 *
 * Usage:
 * Call count(d) to calculate n_d
 */

#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull choose(int, int);
ull count(int);

int main()
{
	cout << "d : n_d\n";
	for (int i = 1; i <= 11; ++i)
		cout << i << " : " << count(i) << "\n";
	return 0;
}

ull choose(int n, int k)
{
	ull a = 1, b = 1;
	for (int i = n-k+1; i <= n; ++i) a *= i;
	for (int i = 1; i <= k; ++i) b *= i;
	return a/b;
}

ull count(int d)
{
	if (d == 1)
		return 1;
	ull nd = 0;
	for (int d1 = 1; d1 < d; ++d1) {
		int d2 = d - d1;
		nd += count(d1) * count(d2) *
			( d1*d1*d2*d2 * choose(3*d-4, 3*d1-2)
			- d1*d1*d1*d2 * choose(3*d-4, 3*d1-1));
	}
	return nd;
}
