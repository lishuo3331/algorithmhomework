#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int t, n, d[20], num1, num2;
int i, j, k, l, r;

int main() {
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        for (j = 1; j <= n; j++) {
            scanf("%d", &d[j]);
        }
        sort(d + 1, d + n + 1);
        if (n == 2) { // 两个数的情况
            printf("%d\n", abs(d[2] - d[1]));
        } else if (n % 2 == 1) { // 奇数个数的情况
            if (d[1] == 0) {
                swap(d[1], d[2]);
            }
            num1 = 0, num2 = 0;
            // 前n/2+1个数从左往右组成第一个整数
            for (j = 1; j <= n / 2 + 1; j++) {
                num1 = num1 * 10 + d[j];
            }
            // 后n/2个数从右往左组成第二个整数
            for (j = n; j >= n / 2 + 2; j--) {
                num2 = num2 * 10 + d[j];
            }
            printf("%d\n", abs(num1 - num2));
        } else { // 偶数个数的情况
            int result = 0x7fffffff;
            // 枚举，取第k个数加入第一个整数中，取第k+1个数加入第二个整数中
            for (j = 1; j < n; j++) {
                if (d[j] == 0) {
                    continue;
                }
                num1 = d[j], num2 = d[j + 1];
                // 从右往左遍历n/2-1个数加入第一个整数中
                // 从左往右遍历n/2-1个数加入第二个整数中
                l = 1, r = n;
                for (k = 0; k < n / 2 - 1; k++) {
                    if (l == j) l++;
                    if (l == j + 1) l++;
                    if (r == j + 1) r--;
                    if (r == j) r--;
                    num1 = num1 * 10 + d[r];
                    num2 = num2 * 10 + d[l];
                    l++, r--;
                }
                // 取差最小的值
                result = min(result, abs(num1 - num2));
            }
            printf("%d\n", result);
        }
    }
    return 0;
}