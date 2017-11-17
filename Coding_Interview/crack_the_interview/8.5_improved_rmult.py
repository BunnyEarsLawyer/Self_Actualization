#!/env/usr/bin python


def mul(a,b):
    if(a > b):
        print('a',a,'b',b)
        a,b = b,a 
        print('a',a,'b',b)
    rmult(a,b)

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
