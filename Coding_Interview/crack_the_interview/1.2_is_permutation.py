#!/usr/bin/env python

def is_permutation(aa, bb):
    if(len(aa) != len(bb)):
        return False

    # aamop -> O(n*log(n))
    my_aa = sorted(aa)
    my_bb = sorted(bb)

    # aamop
    # aamoz -> O(n)
    for my_idx in range(len(my_aa)):
        if(my_aa[my_idx] != my_bb[my_idx]):
            return False

    return True

a = "abc"
b = "aca"

print(is_permutation(a,b))
