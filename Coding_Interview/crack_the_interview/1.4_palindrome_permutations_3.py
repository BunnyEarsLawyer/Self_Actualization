#!/usr/bin/env/ python
import numpy as np
# Removing duplicate items from a list
#for i in mylist:
#    if i not in newlist:
#        newlist.append(i)

def can_be_palindrome(ss):
   my_list = list(ss)
   # convert all to lowercase
   a_list = []
   b_list = []
   for idx in range(len(my_list)):
       curr_char = my_list[idx]
       curr_count = my_list.count(my_list[idx])
       if curr_char not in b_list:
           a_list.append(curr_count) 
           b_list.append(curr_char)
   print(a_list) 
   print(b_list) 
   ab = zip(a_list, b_list)
   ab.sort() 
   print(ab) 

   half_pe = []
   half_ep = []
   if(ab.count(1) > 1):
       return False
   else:
       ab = np.array(ab) 
       half_pe = ab[:,1]
       half_ep = list(reversed(half_pe)) 
       half_pe = list(half_pe)
       palindrome = half_pe + half_ep
       print(palindrome)

sss = 'tacocat'
print(sss)
can_be_palindrome(sss)
