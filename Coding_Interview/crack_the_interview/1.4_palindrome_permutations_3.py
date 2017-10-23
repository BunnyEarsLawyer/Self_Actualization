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
   c_list = []
   d_list = []
   for idx in range(len(my_list)):
       curr_char = my_list[idx]
       curr_count = my_list.count(my_list[idx])
       if curr_char not in b_list:
           if (curr_count % 2 == 0):
               a_list.append(curr_count) 
               b_list.append(curr_char)
           else:
               c_list.append(curr_count)
               d_list.append(curr_char)
   ab = zip(a_list, b_list)
   cd = zip(c_list, d_list)
   ab.sort() 
   print(ab) 
   print(cd) 


   half_pe = []
   half_ep = []
   if(cd.count(1) > 1):
       print('CANNOT MAKE PALINDROME')
   else:
       less_than_two = list(filter(lambda x: x[0] < 2, cd))
#      out_tup = [i for i in ab if i[1] > 2]
       less_than_two = np.array(less_than_two)
       # Gets all rows along the first dim.
       single_char = less_than_two[:,1]
       print(less_than_two) 
       ab = np.array(ab) 
       half_pe = ab[:,1]
       half_ep = list(reversed(half_pe)) 
       half_pe = list(half_pe)
       single_char = list(single_char)
       palindrome = half_pe + single_char +  half_ep
       print(palindrome)

sss = 'tacocat'
print(sss)
can_be_palindrome(sss)
