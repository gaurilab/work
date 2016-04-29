#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;


int main() {
	int po[5];
	int d = 360 * 3;
	const int N = 40;
	while (1) {
		for (int k = 0 ; k < 4 ; ++k) scanf("%d",&po[k]);
		if (!(po[0] || po[1] || po[2] || po[3])) break;
		int ans = 0;
		ans  +=  ((N - po[1] + po[0]) %N)  ;
		ans  += ((N - po[1] + po[2]) %N)  ;
		ans  +=  ((N - po[3] + po[2]) %N)  ;
		printf("%d\n",d + 9 * ans);
	}
	return 0;
}
