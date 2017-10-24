# /env/usr/bin/python

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

v1 = [1,2,3]
maxx = 3
n = 0
total = 0
curr_counter = 0
for a_step in v1: 
    total = total + count_steps(n,maxx,a_step)

print(total)     
print('hi')     
