#/env/bin/python!
"""
Remove duplicated from an unsorted list
"""

unsorted_list = [3,4,1,5,4]

# unsorted_list.remove(1)

print(unsorted_list)

# The algorithm pseudo-code
# - The number of items in the linked list is unknown unless we go
#   through each element.

# The list could be very large.

# My first try would be to sort it. I assume I have a n*log(n) sorting 
# algorithm that can do this for me.

# I do this b/c in the worst case scenario, the duplicate could be at the end
# and the sibling at the beginning. Of course, this assumes this is not a doubly# linked list.

unsorted_list.sort()
print(unsorted_list)

# Next, I would take a pointer to the beginning and one that is right next to it
# Check if they are duplicates. If they are, I remove one of them.




