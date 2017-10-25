# /env/usr/bin/python
import pdb
# n = 0..3, calls this 12 times.
# O(3^n) approx.
def ways(i, memo):
    if i == 0:
        memo[i] = 1
        return 1
    if i < 0:
        return 0
    if i > 0:
        memo[i] = ways(i-3) + ways(i-2) + ways(i-1)
 
def get_ways(n):
    memo = []
    return ways(n, memo)

n = 3 
total = ways(n)
print('grand',total)

#    if(memo[i] == 0):
#        return memo[i]
#    elif(i < 0):
#        return 0 
#    elif(i > 0):
#        return 1
#        memo[i] = ways(i-1, memo) + ways(i-2, memo) + ways(i-3, memo)
