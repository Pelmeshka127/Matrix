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

for i in range(matrix_size):

    for j in range(matrix_size):

        elem = random.randint(-matrix_size, matrix_size)

        delit = random.randint(1, 10)

        elem = elem / delit

        file.write(str(elem) + ' ')

    file.write('\n')

file.close()