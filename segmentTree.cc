#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
typedef vector<int> vi;

class ST
{
    public:
    ST(const vi &_A) {
        A = _A; n = (int)A.size();
        //why 4*n
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
    private:
        vi st;
        vi A;        
        int n;
        int left(int p) {return p<<1;}
        int right(int p) {return (p<<1) +1;}
        void build(int p , int l , int r) {
            printf("build %d %d %d\n", p, l ,r);
            if (l == r) {
                st[p] = l;
            } else {
                build(left(p), l, (l+r)/2);
                build(right(p), (l+r)/2 + 1 , r);
                int p1= st[left(p)];
                int p2 = st[right(p)];
                st[p] = A[p1]< A[p2] ? p1 :p2;
            }
        }

        int rmq(int p, int l, int r, int i, int j) {
            printf("rmq %d %d %d %d %d\n", p, l ,r, i , j);
            if (i > r || j < l) return -1; 
            if (i <= l  && j >= r) return st[p];

            int p1 = rmq (left(p),  l, (l+r)/2, i,j);
            int p2 = rmq (right(p),  (l+r)/2 +1, r, i,j);
            if (p1 == -1) return p2;
            if (p2 == -1) return p1;
            return (A[p1]  <= A[p2]) ? p1 : p2;


        }
};
int main() {
    int arr[] = { 18, 17, 13, 19, 15, 11, 20 };
    vi A(arr, arr + 7);
    ST st(A);
    int a ,  b;
    while (scanf("%d %d",&a, &b) && (a||b)) { 
    printf("RMQ(%d,%d ) = %d\n",a,b, st.rmq(a, b));
    }
    return 0;
}
