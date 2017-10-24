#!/usr/bin/env python 

def off_by_one_or_equal(s1,s2):
    l1 = len(s1)
    l2 = len(s2)
    diff = l1 - l2
    small_sz = min(l1,l2)
    counter = 0

    list_a = list(s1)
    list_b = list(s2)

    if( abs(diff) > 1):
        print('False')
        return False
    elif( abs(diff) <= 1):
        if l1 == l2:
            for idx in range(len(list_a)):
               curr_a = list_a[idx]
               curr_b = list_b[idx] 
               if curr_a != curr_b:
                   counter = counter + 1 
            if(counter>1):
               print(counter, 'False')
               return False
        if l1 != l2:
            for idx in range(len(s1)):
                if s1[idx] not in s2:
                    counter = counter + 1 
            if(counter>1):
               print(counter, 'False')
               return False
        print(counter,'True')
        return True

def check_diff(s1,s2):
    counter = 0
    s1 = list(s1)
    s2 = list(s2)
    for idx in range(len(s1)):
        if s1[idx] not in s2:
            counter = counter + 1 

    if(counter > 1): 
        print(counter, 'F') 
        return False
    else:
        print(counter, 'T') 
        return True


s1 = 'bale'
s2 = 'ale'
s3 = 'pale'
s4 = 'pales'

# check_diff(s1,s2)
#check_diff(s1,s3)
#check_diff(s1,s4)
off_by_one_or_equal(s1,s2)
off_by_one_or_equal(s2,s1) # :(
off_by_one_or_equal(s4,s1) # :)
