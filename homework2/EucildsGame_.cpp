#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;


typedef long long int ll;
typedef pair<int, int> P;
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
const double pi=3.14159265358979323846264338327950288L;
const double eps=1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int INT = 0x7fffffff;
const int MAXN = 433;
const int xi[] = {0, 0, 1, -1};
const int yi[] = {1, -1, 0, 0};


int main() {
    int n, m, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        if(n < m) swap(n, m);
        int Stan = 1;
        while(n/m == 1 && n%m){
            int t = n%m;
            n = m;
            m = t;
            Stan = -Stan;
        }
        if(Stan == 1) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}