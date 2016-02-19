#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;
typedef vector<int> vi;

class FT {
    public :
        FT(const vi & A) {
            build(A);
        }

        int rsq (int b) {
            int sum = 0;
            for (;b; b -= LS1(b)) 
                sum += ft[b-1];
            return sum;
        }
       int rsq(int a , int b) {
           return rsq(b) - (a == 1? 0 : rsq(a-1));
       }
    private:
        int LS1(int x) {
            return (x & -x);
        }
        void build (const vi &A) {
            int N = (int)a.size();
            ft.assign(N+1, 0);

            for (int i = 1 ; i <= N ; ++i) {
                int j = i;
            for (;j < i; --j)  {    
                s += A[j-1];
            }
            ft[i] = s;
            printf("%d", ft[i]);
        }
        vi ft;

};
int main() {
    int f[] = {2,4,5,5,6,6,6,7,7,8,9};
    vi F(f, f+sizeof(f)/sizeof(int));
    
    return 0;
}
