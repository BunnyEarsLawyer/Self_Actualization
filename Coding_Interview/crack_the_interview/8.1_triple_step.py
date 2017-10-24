# /env/usr/bin/python
# Try 2
def count_steps(n, maxx, step_sz):
    print(n, maxx)
    if(n == maxx):
        return 1
    elif(n < maxx):
        n = n + step_sz
        count = count_steps(n, maxx, step_sz)
        return count
    else:
        return 0

def ways(n, maxx, steps):
    diff = maxx - n
    if(diff == 0):
        return 1
    elif(n < maxx):
        count = 0
        for step in steps:
           print('n', n, 'step', step)
           n = n + step
           curr_count = ways(n, maxx, steps)
           print('n', n, 'step', step, 'counter', curr_count)
           count = count + curr_count
        return count
    elif(n > maxx):
        return 0 

v1 = [1,2,3]
maxx = 3
n = 0
total = 0
curr_counter = 0
#for a_step in v1: 
#    total = total + count_steps(n,maxx,a_step)

total = ways(n,maxx,v1)
print('grand',total)
print(total)     
print('hi')     
