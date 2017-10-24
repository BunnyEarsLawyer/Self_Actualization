#!/usr/bin/env python 

def compression(s1):
    print(s1)
    v1 = list(s1)
    ll = len(s1)
    v2 = []
    counter = 0
    listoflists = []
    a_list = []
    idx = 0
    prev_char = v1[idx]
    curr_char = prev_char
    for jdx in range(len(v1)):
        curr_char = v1[jdx] 
        if(curr_char == prev_char):
            counter = counter + 1
        if(curr_char != prev_char or jdx==len(v1)-1):
            a_list.append(prev_char)
            a_list.append(counter) 
            prev_char = curr_char
            counter = 1
        print(curr_char,counter)
    print(a_list)
s1 = 'aabcccccaa'
compression(s1)
