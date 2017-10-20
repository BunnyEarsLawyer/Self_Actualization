#!/usr/bin/env python
ss = "Mr John Smith    "
print(len(ss))
zz = "%20"
true_sz = 13

new_ss = ""

my_list = ss.split(" ")
for my_idx in my_list:
   print(my_idx)
   combo_word = my_idx + zz
   print(combo_word)
   new_ss = new_ss + combo_word

print(new_ss)
#for my_idx in range(len(ss)):
#    curr_char=ss[my_idx]
#    if(curr_char==" "):
#        current_word = ss[:my_idx]
#        print(current_word)
#        print("YES")
#        new_ss = current_word + zz

#print(my_list)
#print(my_new_list)
# I won't make a function def. yet.
# Oops, 13 means the extra white spaces not counted.
# An assumption of this that I didn't see is that
# The original string must be edited.
# Because that is why it matters that we have extra space.
