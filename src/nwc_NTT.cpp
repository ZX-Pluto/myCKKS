#include<iostream>
#include<vector>
using namespace std;
class Ntt {
public:
	long p;
	long w;
	long n;
	vector<long> arrw;
	vector<long> revw;
	Ntt(long p, long w, long n):p(p),w(w),n(n) {
		
		arrw.resize(1 << n);
		arrw[0] = 1;
		for (long i = 1; i < (1<<n); i++) {
			arrw[i] = arrw[i - 1] * w % p;
		}
		revw.resize(1 << n );
		revw[0] = 0;
		for (long i = 0; i <= (1<<(n-1)); i++)
			revw[i] = (revw[i >> 1] >> 1) | ((i & 1) << (n - 2));
	}

	vector<long> ntt(vector<long> a) {
		long k = 0;
		for (long mid = (1<<(n-2)); mid > 0; mid>>=1) {
			
			for (long start = 0; start < (1<<(n-1)); start+=mid*2) {
				long wk = arrw[revw[++k]];
				for (long pos = start; pos < start + mid; pos++) {
					long l = a[pos];
					long r = a[pos + mid] * wk % p;
					
					a[pos] = (l + r) % p;
					a[pos + mid] = (l - r) % p;
					if (a[pos] < 0)a[pos] += p;
					if (a[pos + mid] < 0)a[pos+mid] += p;
					// cout << wk << endl;
					// for (auto i : a)cout << i << ' ';
					// cout << endl << endl;
				}
			}

		}
		
		return a;
	}
	vector<long> rntt(vector<long> a) {
		long k = (1<<(n-1));
		for (long mid = 1; mid <= (1 << (n - 2)); mid <<= 1) {
			for (long start = (1 << (n - 1)) - mid*2; start >= 0; start -= mid * 2) {
				long wk = arrw[((1<<n))-revw[--k]];
				for (long pos = start; pos<start+mid; pos++) {
					// cout <<"start: "<<start<<" pos: "<< pos << " mid: " << mid << endl;
					long add = (a[pos] + a[pos + mid]) % p ;
					long minus = (a[pos] - a[pos + mid])*wk % p ;
					if (add < 0)add += p;
					if (minus < 0)minus += p;
					if (add % 2)add += p;
					a[pos] = add/2;
					if (minus % 2)minus += p;
					a[pos + mid] = minus/2;

					// cout << wk << endl;
					// for (auto i : a)cout << i << ' ';
					// cout << endl << endl;
				}
			}

		}

		return a;
	}
	
};
int main() {
	Ntt tmp(12289, 7, 10);
	// Ntt tmp(17, 2, 3);
	long* xp = new long[1024];
	for (size_t i = 0; i < 1024; i++)
	{
		*(xp + i) = 1;
		// if(i > 4) *(xp + i) = 2;
		// if(i > 8) *(xp + i) = 3;
	}
	vector<long> my_a(xp,xp+1024);
	// my_a.begin() = xp;
	auto vec=tmp.ntt(my_a);
	for (auto i : vec) {
		if (i < 0)
			cout << i + 12289 << ' ';
		else
		cout << i << ' ';
	}cout << endl;

    // for (int i = 0; i < vec.size(); i++) {
	// 	vec[i] = vec[i] * vec[i] % 12289;
	// }
    // for (auto i : vec) {
	// 	if (i < 0)
	// 		cout << i + 12289 << ' ';
	// 	else
	// 	cout << i << ' ';
	// }cout << endl;
    vec = tmp.rntt(vec);
    for (auto i : vec) {
		if (i < 0)
			cout << i + 12289 << ' ';
		else
		cout << i << ' ';
	}cout << endl;
}