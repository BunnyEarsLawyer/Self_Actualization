#!/env/usr/bin python

def is_rot(s1,s2,n):
    l1 = list(s1)
    l2 = list(s2)
    sub_s1  = l1[:-n]
    print(sub_s1)
    if is_substring(sub_s1,s2):
       return True
    else:
       is_rot(s1,s2,n+1)

print('hi')
n = 0
is_rot('abc','cab',n)
