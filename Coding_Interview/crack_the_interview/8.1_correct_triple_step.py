# /env/usr/bin/python
import pdb
# n = 0..3, calls this 12 times.
# O(3^n) approx.
def ways(n):
    if(n == 0):
        return 1
    elif(n < 0):
        return 0 
    elif(n > 0):
        return ways(n-1) + ways(n-2) + ways(n-3)

n = 3 
total = ways(n)
print('grand',total)
