#!/env/urs/bin pythong
import numpy as np
n = 2
m = 2
# REVIEW***How to make 2d matrix
a = [[0,3,0],[2,6,3]]
nm_matrix = np.array(a)
a_list = []
# REVIEW***How iterate through 2d matrix
for idx, x in np.ndenumerate(a):
    if x==0:
        a_list.append(idx) 
    print(idx)
    print(x)

for ii in range(len(a_list)):
    curr_idx = a_list[ii]
    row = curr_idx[0]
    col = curr_idx[1]
    print(row)
    print(col)
    print(nm_matrix)
    # REVIEW***How edit all row items or column item 
    nm_matrix[row,:] = 0
    nm_matrix[:,col] = 0
    print(nm_matrix)

print("hi")
