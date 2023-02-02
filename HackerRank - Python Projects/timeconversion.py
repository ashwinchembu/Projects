#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Write your code here
    n = ""
    if s[-2] == 'A':
        if s[:2] == '12':
            n += '00'
        else:
            n += s[:2]
    else:
        if s[:2] != '12':
            n += str(int(s[:2]) + 12)
        else:
            n += s[:2]
    n += s[2:8]
    return n
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
