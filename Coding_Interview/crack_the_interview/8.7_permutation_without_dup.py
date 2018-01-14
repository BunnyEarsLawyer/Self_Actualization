#! /usr/bin/env python

# Get permutations
def get_permutations(ww):
    permutations = [] 
    if ww == None:
        return None

    n = len(ww)

    # Base case, n = 0
    if n == 0:
        permutations.append("")
        return permutations
    if n != 0:
        words = []
        # Get the first char
        first_char = ww[0]
        # Remove the first char
        remainder = ww.replace(first_char,'')
    
        words = get_permutations(remainder)
 
        for word in enumerate(words):
            for idx, val in enumerate(word):
                 print(idx, val, word, words)
#                ss = insert_char_at(word, first_char, idx)
#                permutations.append(ss)
#                print(permutations)

        return permutations 

def insert_char_at(word, char, idx):
   start = word[0:idx] 
   end   = word[idx:]
   return start + char + end;

print ('->hi')
word = 'abc' 
# Testing insert_char_at
# word = insert_char_at(word,'z',1)
# print(word)
# permucat('1234')
pp = get_permutations(word)
print(pp)
#             before = words[0:idx]
#             curr_sent = words[idx]
#             after  = words[idx:l]
