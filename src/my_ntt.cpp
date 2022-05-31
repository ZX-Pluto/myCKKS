#include <bits/stdc++.h>
typedef long long ll;
const int NR = 1 << 22, g = 3, gi = 332748118, mod = 998244353;
//998244353的一个原根为3且998244353-1=2^23*119，3在模998244353意义下的逆元为332748118
using namespace std;
int n, m, rev[NR]; //rev[i]为i的二进制翻转
long a[NR], b[NR];
long fast_power(long a, long k) //快速幂，a为底数，k为指数
{
    long res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}
void NTT(long *a, int n, int type) //NTT，type=1时系数表示法转点值表示法，否则点值表示法转系数表示法
{
    for (int i = 0; i < n; ++i) //先将a变成最后的样子
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int i = 1; i < n; i <<= 1)
    {                                                            //在这之前NTT与FFT无异
        long gn = fast_power(type ? g : gi, (mod - 1) / (i << 1)); //单位原根g_n
        for (int j = 0; j < n; j += (i << 1))                    //枚举具体区间，j也就是区间右端点
        {
            long g0 = 1;
            for (int k = 0; k < i; ++k, g0 = g0 * gn % mod) //合并，记得要取模
            {
                long x = a[j + k], y = g0 * a[i + j + k] % mod;
                a[j + k] = (x + y) % mod;
                a[i + j + k] = (x - y + mod) % mod;
            }
        }
    }
}
int main()
{
    // scanf("%d%d", &n, &m);
    // for (int i = 0; i <= n; ++i) //输入第一个多项式
    //     scanf("%longd", a + i);
    // for (int i = 0; i <= m; ++i) //输入第二个多项式
    //     scanf("%longd", b + i);
    // int len = 1 << max((int)ceil(log2(n + m)), 1); //由于NTT需要项数为2的整数次方倍，所以多项式次数len为第一个大于n+m的二的正整数次方
    int len = 8;
    long l = 0;
    while ((1 << l) < len) ++l;
    long* xp = new long[32];
	for (size_t i = 0; i < 32; i++)
	{
		*(xp + i) = 1;
		if(i > 3) *(xp + i) = 0;
		if(i > 8) *(xp + i) = 3;
	}
	vector<long> my_a(xp,xp+len);

    for (int i = 0; i < len; ++i)                  //求rev
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    NTT(xp, len, 1);
    // NTT(a, len, 1); //系数表示法转点值表示法
    // NTT(b, len, 1);
    for (int i = 0; i < len; ++i)
        xp[i] = xp[i] * xp[i] % mod;          //O(n)乘法
    // NTT(a, len, 0);                        //点值表示法转系数表示法
    NTT(xp, len, 0);
    long inv = fast_power(len, mod - 2);     //inv为len的逆元（费马小定理求逆元）
    for (int i = 0; i < len; ++i)       //输出
        printf("%ld ", xp[i] * inv % mod); //除以len在模mod意义下即为乘以inv
    return 0;
} 