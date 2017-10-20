#!/usr/bin/env python

def has_unique_chars(word):
    count = 0
    # Sort
    ss = sorted(word)
    print("Iterating",ss) 
    # Iterate through each. O(n) 
    for cc in range(len(ss)):
        print(ss[cc])
        count = ss.count(ss[cc])
        if(count > 1):
            print("repeated chars", count) 
            return False
    return True 
    # Count instances.
    # aa.count()

a = "abc"
b = "aca"

has_unique_chars(a)
has_unique_chars(b)
