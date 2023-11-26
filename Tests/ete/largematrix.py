import random

import os

matrix_size = int(input("Input the size of matrix: "))

all_files = os.listdir()

max_test_number = 0

for file in all_files:

    if (file.endswith('.dat')):

        test_number = int(file[:-4])

        if (test_number > max_test_number):
            max_test_number = test_number

file = open(str(max_test_number + 1).zfill(3) + ".dat", "w")

file.write(str(matrix_size) + '\n\n')

half_space = random.randint(1, 2)

if (half_space % 2 == 0):
    
    for i in range(matrix_size):

        for j in range(i):

            file.write(str(0) + ' ')

        for j in range(matrix_size - i):
            
            elem = random.randint(-4, 4) / random.randint(1, 4)

            if (elem == 0):
                elem = 1

            file.write(str(elem) + ' ')

        file.write('\n')

else:

    for i in range(matrix_size):

        for j in range(i + 1):

            elem = random.randint(-4, 4) / random.randint(1, 4)

            if (elem == 0):
                elem = 1

            file.write(str(elem) + ' ')

        for j in range(matrix_size - i - 1):

            file.write(str(0) + ' ')

        file.write('\n')


file.close()