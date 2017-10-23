#!/usr/bin/env/ python

def can_be_palindrome(ss):  #"Aabb"
   my_list = list(ss)  #[A,a,b,b] 
   # convert all to lowercase
   # sort the list.
   my_list.sort()
   a_list = []
   prev_char = my_list[0]
   for idx in range(len(my_list)):
       # count each instance of a letter.
       curr_char = my_list[idx]
       if(curr_char == prev_char):
           idx= idx+1
       else:
           curr_count = my_list.count(curr_char)
           # list of tuples (key= letter, value = count) (no dictionary)
           a_list.append((curr_char, curr_count)) 

   final_list = []
#  final_list.size() = my_list.size() 

   for jdx in range(len(a_list)):
       curr_char = a_list(jdx[0])
       curr_count = a_list(jdx[1])
       if(curr_count %2 == 0 ):
          half_list = a_list(jdx[0])       
       elif(curr_count == 1):
          last_char = curr_char 

   half_palindrome = half_list + last_char
   # reverse half list, add it to half palindrome.
   palindrom = half_list + last_char + reverse_half_list
   # convert to string
   palindrome = "".join(final_list)
   return palidrom 

print('tacocat')
sss = 'tacocat'
can_be_palindrome(sss)
