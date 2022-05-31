# import math


# def bit_reverse(coeffs): 
#     degree = len(coeffs) 
#     result = [0] * degree 
#     for i in range(degree): index_binary = '{:0{width}b}'.format(i, width=int(math.log(degree, 2))) 
#     bit_reversed_index = int(index_binary[::-1], 2) 
#     result[i] = coeffs[bit_reversed_index] 
#     return result

# arrw = [1, 1, 1, 1]
# arrw = bit_reverse(arrw)
# print(arrw)

import random
import math
import os
import sys

#precompute the twiddle factors
w_rom = []
kesai = 7315
q = 12289
inv_kesai = pow(kesai,2047) % q

def bitreverse(n,l):
    r = 0
    for i in range(l):
        r = (r << 1) | (n & 1)
        n = n >> 1
    return r

for i in range(1024):
    w_rom.append(pow(kesai,bitreverse(i,10)) % q)

# print(w_rom)
#print(len(w_rom))
#print(inv_kesai)
def printlog(content):
        # 以日期+时间命名生成txt文件
        # 获取当前文件绝对路径
        path = os.path.abspath(os.path.dirname(sys.argv[0]))
        sys.stdout = open(path+'/ntt_python.txt', mode='a+', encoding='utf-8')
        print(content)

def DIT_NR_NTT(a,w_rom):
    n = len(a)
    log_n = int(math.log(n,2))
    r = 1
    # my_i = 0
    for p in range(log_n-1,-1,-1):
        # print(p)
        J = int(pow(2,p))
        for k in range(int(n/(2*J))):
            w = w_rom[r]
            r = r + 1
            for j in range(J):
                u = a[k*2*J+j] % q
                t = (a[k*2*J+j+J] * w) % q
                # my_i = my_i + 1
                # if my_i < 2:
                #     print("a[k*2*J+j+J] = ", a[k*2*J+j+J])
                #     print("w = ", w)
                #     print("u = ", u)
                #     print("u - t = ", (u+q-t))
                #     print("a[k*2*J+j+J] = ", a[k*2*J+j+J])
                # printlog("k*2*J+j+J = " +  "%d" % (k*2*J+j+J) + "; a[k*2*J+j+J] = " +  "%d" % (a[k*2*J+j+J]) + \
                # "; u = " +  "%d" % u + "; t = " +  "%d" % t + \
                # "; u + t = " +  "%d" % (u + t) + "; u - t = " +  "%d" % (u - t))
                a[k*2*J+j] = (u + t) % q
                a[k*2*J+j+J] = (u + q - t) % q
                # printlog("a[" + "%d" % (k*2*J+j) + "] = " + "%d" % a[k*2*J+j] + "; a[" + "%d" % (k*2*J+j+J) + "] = " + "%d" % a[k*2*J+j+J])

    return a

def op21(a):
    if a & 1 == 0:
        r = (a >> 1) % q
    else:
        r = ((a >> 1) + ((q + 1)>>1)) % q
    return r

def DIF_RN_INTT(a,w_rom):
    n = len(a)
    log_n = int(math.log(n,2))
    r = len(w_rom)-1
    my_i = 0
    for i in range(log_n):
        J = int(pow(2,i))
        for k in range(int(n/(2*J))):
            w = w_rom[r]
            r = r - 1
            for j in range(J):
                u = a[k*2*J+j] % q
                t = a[k*2*J+j+J] % q
                my_i = my_i + 1
                if my_i < 2:
                    print("k*2*J+j+J = ", k*2*J+j+J)
                    print("a[k*2*J+j+J] = ", a[k*2*J+j+J])
                    print("w = ", w)
                    print("u = ", u)
                    print("u - t = ", (u+q-t))
                a[k*2*J+j] = (op21(u + t)) % q
                a[k*2*J+j+J] = (op21(t + q - u) * w) % q
    return a

def pwm(x,y):
    q = 12289
    N = len(x)
    z = []
    for i in range(N):
        z.append((x[i] * y[i]) % q)
    return z


def test():
    a = []
    for i in range(1024):
        a.append(i)
    b = [0] * 1024
    b[0] = 1
    ffta = DIT_NR_NTT(a,w_rom)
    fftb = DIT_NR_NTT(b,w_rom)
    print("ffta = ",ffta)
    print("fftb = ",fftb)

    c = pwm(ffta,fftb)
    print("c = ",c)

    ifftc = DIF_RN_INTT(c,w_rom)
    print("ifftc = ",ifftc)

test()