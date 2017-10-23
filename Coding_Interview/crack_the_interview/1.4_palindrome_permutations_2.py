#!/usr/bin/env/ python
import numpy as np
# Removing duplicate items from a list
#for i in mylist:
#    if i not in newlist:
#        newlist.append(i)

def can_be_palindrome(ss):
   my_list = list(ss)
   # convert all to lowercase
   # sort the list.
   my_list.sort() #tacocat aaccott
   a_list = []
   b_list = []
   M = np.array([], dtype=object)
   for idx in range(len(my_list)):
       curr_char = my_list[idx]
       print(curr_char)
       curr_count = my_list.count(my_list[idx])
       print(curr_count)
       if curr_char not in a_list:
           a_list.append(curr_count) 
           b_list.append(curr_char)
   print(a_list) 
   print(b_list) 

   nd_array = np.column_stack( (a_list, b_list) )
   
   print (nd_array)       
   blah = np.where(nd_array == 1)
   print(blah)
   np.sort(nd_array, axis=0)
   print (nd_array)       
#  [value for value in nd_array if value > 2] 

sss = 'tacocat'
print(sss)
can_be_palindrome(sss)
