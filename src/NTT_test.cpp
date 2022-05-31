#include<bits/stdc++.h>
#include<complex>
using namespace std;
#define cp complex<double>

  
template <typename T>
void print_vector(vector<T> vector_temp){
    cout << "{";
    for(auto item : vector_temp) cout << item << ",";
    cout << "\b}";
}

template <typename T>
void print_array(T *array_temp,size_t len){
    cout << "{";
    for (size_t i = 0; i < len; i++)  cout << array_temp[i] << ",";
    cout << "\b}";
}

void simple_fft(cp *a,int n,int inv = 1)//inv是取共轭复数的符号
{
    if (n==1)return;
    int mid= n >> 1;
    static cp *b = new cp[n];
    for(int i = 0; i < mid; i++)
    {
        b[i]=a[i*2],b[i+mid]=a[i*2+1];
    }
    for(int i = 0; i < n; i++)a[i]=b[i];
    cout << "fuck_a :";
    print_array(a,8);
    cout << endl;
    simple_fft(a,mid,inv);
    simple_fft(a + mid,mid,inv);//分治
    for(int i = 0; i < mid; i++)
    {
        cp x(cos(2*M_PI*i/n),inv*sin(2*M_PI*i/n));//inv取决是否取共轭复数
        b[i]=a[i]+x*a[i+mid],b[i+mid]=a[i]-x*a[i+mid];
    }
    for(int i = 0; i < n; i++) a[i]=b[i];
}

void fft(vector<cp> &a,int n,int inv = 1)
{
    int bit = 0;
    while ( (1 << bit) < n ) bit++;
    int *rev = new int[n];
    for (size_t i = 0; i < n; i++)   //不加这条if会交换两次（就是没交换）;数组是按索引的二进制逆序存放的，所以需要将它还原
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit-1));
        if (i < rev[i]) swap(a[i],a[rev[i]]);
    }
    for (int mid = 1;mid < n;mid <<= 1)//mid是准备合并序列的长度的二分之一
    {
    	cp temp(cos(M_PI/mid),inv*sin(M_PI/mid));//单位根，pi的系数2已经约掉了
        for (int i=0;i<n;i+=mid*2)//mid*2是准备合并序列的长度，i是合并到了哪一位
		{
            cp omega(1,0);
            for (int j=0;j<mid;j++,omega*=temp)//只扫左半部分，得到右半部分的答案
            {
                cp x=a[i+j],y=omega*a[i+j+mid];
                a[i+j]=x+y,a[i+j+mid]=x-y;//蝴蝶变换
            }
        }
    }
}


#define g 3//模数的原根
#define M 998244353//通常情况下的模数

typedef long long ll;

ll helper(ll i, ll power){
    /*
        i: 要逆序的整数
        power: 2**(r-2)
    */
    ll res = 0;
    while(i){
        if(i&1) res += power;
        i >>= 1;
        power >>= 1;
    }
    return res;
}

ll qpow(ll a,ll b)//快速幂
{
	ll ans = 1;
    while(b){
        if (b & 1) ans = ans*a % M;
        a = a*a % M;
        b >>= 1;
    }
    return ans;
}

void NTT(vector<ll> &x, int inv=1)
{
    int len = x.size();
    ll l = 0;
    while ((1 << l) < len) ++l;
    ll *rev = new ll[len];
    for (size_t i = 0; i < len; i++)   //数组是按索引的二进制逆序存放的，所以需要将它还原
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l-1));
        if (i < rev[i]) swap(x[i],x[rev[i]]);
    }

    for(ll r = 1; r < l+1; r++)
    {
        ll mid = 1 << (r-1);
        ll t = qpow(g, (M-1) >> r);
        if(inv == -1) t = qpow(t, M-2);

        for(ll i = 0; i < len; i += 1 << r)
        {
            ll a_p = 1;
            for(ll j = 0; j < mid; j++)
            {
                ll u = x[i+j], v = x[i+j+mid] *a_p %M;
                x[i+j] = (u+v) % M;
                x[i+j+mid] = (u-v) % M;
                a_p = a_p * t % M;
            }
        }
    }
}

int main()
{
    cout << "##### simple_fft start #####" << endl;
    int simple_fft_len = 8;
    int simple_fft_mid = simple_fft_len >> 1;
    cp *simple_fft_a = new cp[simple_fft_len];
    cp *simple_fft_b = new cp[simple_fft_len];
    for (size_t i = 0; i < simple_fft_mid; i++)
    {
        simple_fft_a[i].real(1);
        simple_fft_a[i].imag(0);
        simple_fft_b[i].real(1);
        simple_fft_b[i].imag(0);
    }
    cout << "polynomial_a :";
    print_array(simple_fft_a,simple_fft_len);
    cout << endl;
    // cout << "polynomial_b :";
    // print_array(simple_fft_b,simple_fft_len/2);
    // cout << endl;

    simple_fft(simple_fft_a, simple_fft_len);
    // simple_fft(simple_fft_b, simple_fft_len/2);
    cout << "after_NTT_polynomial_a :";
    print_array(simple_fft_a,simple_fft_len);
    cout << endl;
    simple_fft(simple_fft_a, simple_fft_len , -1);
    cout << "after_multi_polynomial_c :";
    print_array(simple_fft_a,simple_fft_len);
    cout << endl;

    // cp *simple_fft_c = new cp[simple_fft_len];
    // for (size_t i = 0; i < simple_fft_len; i++)
    // {
    //     simple_fft_c[i] = simple_fft_a[i] * simple_fft_b[i];
    // }
    // simple_fft(simple_fft_c, simple_fft_len , -1);
    // cout << "after_multi_polynomial_c :";
    // print_array(simple_fft_c,simple_fft_len);
    // cout << endl;
    exit(0);

    cout << "##### fft start #####" << endl;
    int fft_len = 8;
    int fft_mid = fft_len >> 1;
    vector<cp> fft_a(fft_len),fft_b(fft_len);
    for (size_t i = 0; i < fft_mid; i++)
    {
        fft_a[i].real(1);
        fft_a[i].imag(0);
        fft_b[i].real(1);
        fft_b[i].imag(0);
    }
    cout << "polynomial_a :";
    print_vector(fft_a);
    cout << endl;
    cout << "polynomial_b :";
    print_vector(fft_b);
    cout << endl;

    fft(fft_a, fft_len);
    fft(fft_b, fft_len);
    cout << "after_NTT_polynomial_a :";
    print_vector(fft_a);
    cout << endl;

    fft(fft_a, fft_len , -1);
    cout << "after_multi_polynomial_c :";
    print_vector(fft_a);
    cout << endl;

    // vector<cp> fft_c(fft_len);
    // for (size_t i = 0; i < fft_len; i++)
    // {
    //     c[i] = a[i] * b[i] % M;
    // }
    // fft(fft_c, fft_len,-1);
    // cout << "after_multi_polynomial_c :";
    // print_vector(fft_c);
    // cout << endl;

    cout << "##### NTT start #####" << endl;
    int len = 8;
    int mid = len >> 1;
    vector<ll> a(len),b(len);
    for (size_t i = 0; i < mid; i++)
    {
        a[i] = 1;
        a[i + mid] = 0;
        b[i] = 1;
        b[i + mid] = 0;
    }
    cout << "polynomial_a :";
    print_vector(a);
    cout << endl;
    cout << "polynomial_b :";
    print_vector(b);
    cout << endl;

    NTT(a);
    NTT(b);
    cout << "after_NTT_polynomial_a :";
    print_vector(a);
    cout << endl;

    NTT(a,-1);
    cout << "after_multi_polynomial_c :";
    print_vector(a);
    cout << endl;

    // vector<ll> c(len);
    // for (size_t i = 0; i < len; i++)
    // {
    //     c[i] = a[i] * b[i] % M;
    // }
    // NTT(c,-1);
    // cout << "after_multi_polynomial_c :";
    // print_vector(c);
    // cout << endl;

    return 0;
}