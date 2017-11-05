#!/usr/bin/env python

#       0 1 2 3 4
# A = [-1,1,7,8,9] // 1

def find_magic(A):
    print(A)
    # 1. check if it's possible to have magic idx's or if A is empty.
    if( len(A) == 0): 
        return

    n = len(A) # = 5
    minn = 0        #always
    maxx = n-1 # = 4
    curr_val = A[maxx/2]
    curr_idx = maxx/2
    bottom_edge = A[0]   #-1
    top_edge    = A[n-1] #9
    
    # if(top_edge < minn) or (bottom_edge > maxx):
    #    print('no magic')
    #    print(A, top_edge, minn, bottom_edge, maxx)    
    
    # 2. Base case
    # [ A  ]
    # [B][C]
    if curr_val == curr_idx:
        print(curr_val)
        # Weird python, no need for a comma
        B = A[:curr_idx - 1]
        C = A[curr_idx + 1:] 
        find_magic(B)
        find_magic(C)
    
    if curr_val > curr_idx:
        B = A[:curr_idx]
        find_magic(B)
    
    if curr_val < curr_idx:
        C = A[curr_idx + 1:] 
        find_magic(C)  # This is like a keyword GOTO beginning :)

# A = [0,1,2]
# A = [-1,1,2,3,4]
A = [-1,1,7,8,9] # Magic index 1
print(A)

#Upper and Lower arrays
#L = A[:len(A)/2]
#print(L)
#H = A[len(A)/2:]
#print(H)

find_magic(A)
