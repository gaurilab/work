#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <cstring>
#include <map>
#include <cctype>
using namespace std;
int main() {
	char wish[55] = {0};
	size_t len = 40;
	std::map<string,string> lookup;
	lookup["HELLO"]= "ENGLISH";
	lookup["HOLA"] = "SPANISH";
	lookup["HALLO"] = "GERMAN";
	lookup["BONJOUR"] = "FRENCH";
	lookup["CIAO"] = "ITALIAN";
	lookup["ZSRAVSTVUJTE"] = "RUSSIAN";
	int i = 0 ;
	while (!cin.fail()) {//(char*)NULL) {
		cin.getline(wish, len);
		if (string(wish).compare("#") == 0) break;
		std::map<string, string>::iterator it = lookup.find(wish);
		printf("Case %d: %s\n",++i, it != lookup.end() ? it->second.c_str(): "UNKNOWN");
	}
	return 0;
	}
