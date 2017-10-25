# /env/usr/bin/python
import pdb

def ways(n, maxx, steps, count):
    diff = maxx - n
#   count = 0
    if(diff == 0):
        return count + 1
    elif(n < maxx):
        for step in steps:
           print('n', n, 'step', step, 'count t', count)
           n = n + step
           curr_count = ways(n, maxx, steps, count)
           count = count + curr_count
#          pdb.set_trace()
           print('n', n, 'step', step, 'counter x', curr_count, 'count t', count)
        print('final_count', count)
        return count
    elif(n > maxx):
        return 0 

v1 = [1,2,3]
maxx = 3
n = 0
total = 0
curr_counter = 0

ways(n,maxx,v1,total)
print('grand',total)
