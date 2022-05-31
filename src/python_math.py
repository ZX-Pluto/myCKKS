import math
import time
count = 1

print(pow(1029358202768165328, 8192<<1, 1067353111686807553))
print(1067353111686807553 % (8192<<1))
# print(pow(7315, 2048, 12289))
# p = 1067353111686807553
# def find_root(p,n):
#     i = 2
#     while i < p - 1:
#         temp = i
#         j = 2
#         while j <= n:
#             temp = pow(temp, 2, p)
#             if temp == 1 and j < n:
#                 i = i+1
#                 break
#             if temp == 1 and j == n:
#                 return i
#             j = j << 1
# p = 970662608897
# p = 966367641601
# p = 263882790666241
# p = 1067353111686807553
# p = 1067353111686807553
# n = 8192
# for i in range(2, p-1):
#     temp = i
#     j = 2
#     passing = False
#     while j <= n:
#         temp = pow(temp, 2, p)
#         if temp == 1:
#             if j == n:
#                 passing = True
#             break
#         j = j<<1
#     if passing:
#         print(i)
#         break

# find_root(12289,2048)
# def GCD(x, y):
#     if x > y:
#         small = y 
#     else:
#         small = x 
#     for i in range(1, small+1):
#         if((x % i == 0) and (y % i == 0)):
#             gcd = i 
              
#     return gcd 

# print(pow(5846,2) % 12289)

# print(GCD(722,12289))