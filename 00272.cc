#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;


int main() {
	bool to = false;
	char c;
	while ((c = getchar()) != EOF) {
		if (c =='"') {
			if (to) {
				putchar('\'');
				putchar('\'');
			} else {
				putchar('`');
				putchar('`');
			}
			to = !to;
		} else {
			putchar(c);
		}
	}
	return 0;
}
