#!/usr/bin/env python

def magic_index(A):
    for idx in A:
        if(A[idx] == idx):
            print(idx)

# A = [0,1,2]
A = [-1,1,2]
print(A)

magic_index(A)
