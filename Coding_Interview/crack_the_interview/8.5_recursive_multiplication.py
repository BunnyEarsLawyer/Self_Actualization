#!/env/usr/bin python

def rmult(a,b):
    if(b == 0):
        return 0;
    if(b > 0):
        b = b - 1; 
        a = a + rmult(a,b)
        return a

print('hi')

result = rmult(1,2)
print(result)
