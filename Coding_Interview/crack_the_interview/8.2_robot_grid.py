# /env/usr/bin/python

def paths(r,c, vv):
    if(r == 0 or c == 0):
        vv.append((r,c))
        return 
    if(r > 0 or c > 0):
        vv.append((r,c))
        paths(r-1,c, vv)
        paths(r,c-1, vv)
    if(r < 0 or c < 0):
        return
    return vv

vv = []
paths(1,1, vv)
print vv
