import numpy as np
from collections import Counter
input_list = ['X', 'B', 'G', 'X', 'G']
to_set = set(input_list)
to_dict = Counter(input_list)
to_uniqeElement = np.unique(input_list)

#import Counter
# input list
input_list = ['X', 'B', 'G', 'X', 'G']

# keys of the dictionary will be the unique items
print(Counter(input_list).keys())

# values will be the number of that key present in the list
print(Counter(input_list).values())

# new list with key-value pairs
print(Counter(input_list))

# count of unique values
print("Count- ", len(Counter(input_list)))

# input list
input_list = [1, 4, 4, 1, 9]

# converts list to set
to_set = set(input_list)

# prints count of unique values
print("Count- ", len(to_set))

#numpy is imported

# input list
input_list = [4, 6, 2, 6, 7, 4, 2, 2, 0]

# prints unique elements
print("Unique elements are- ", np.unique(input_list))

# prints total number of unique elements
print("Count of unique elements- ", len(np.unique(input_list)))
