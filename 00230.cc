#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits>
#include <cerrno>

using namespace std;


typedef vector<pair<string, string> > li;
typedef li::iterator lit;

int main() {
	string in;

	char op[40] = {0};
	char title[100] = { 0};
	char auth[100] = { 0};
	li all;
	while (getline(cin, in) && in.compare("END") != 0) {
		//printf("%s\n", in.c_str());
		//sscanf(in.c_str(),"\"%[^\"]s by %[^\n]s", title, auth);
		int r = sscanf(in.c_str(),"\"%[^\"]s\" %s", title, auth);
		//printf("title : [%s] auth: [%s] %d %d\n", title, in.c_str() + strlen(title) + 6 ,r, errno);
		all.push_back(make_pair(string(title), string(in.c_str() + strlen(title) + 6)));
	}
	sort(all.begin(), all.end());
	vector<int> state;
	state.assign(all.size(),1);

	while (getline(cin, in) && in.compare("END") != 0) {
		sscanf(in.c_str(),"%s \"%[^\"]s\"", op, title);

		//printf("%s %s\n", op, title);
		if (string(op).compare ("SHELVE") == 0) {
			for (int  k = 0 ; k < all.size(); ++k) {
				if (state[k] == 2) {
					if (k == 0 ) {
						printf("Put %s first\n ",all[k].first.c_str());
					} else {
						printf("Put %s after %s\n ",all[k].first.c_str(), all[k-1].first.c_str());
					}
					state[k] = 1;
				}
			}
			continue;
		} 
		int i = 0;
		for (; i < all.size() ; ++i) {
			 if (all[i].first.compare(title) == 0) break;
		}
		if (string(op).compare ("RETURN") == 0) {
			state[i] = 2;
		} else if (string(op).compare ("BORROW") == 0) {
			state[i] = 0;
		} else {
			break;
		}
	}
	return 0;
}
