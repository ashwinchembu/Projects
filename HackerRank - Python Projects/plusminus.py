#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    p = 0
    n = 0
    z = 0
    for i in arr:
        if i > 0:
            p += 1
        elif i < 0:
            n += 1
        else:
            z += 1
    print(round(float(len(p)/len(arr)),6))
    print(round(float(len(n)/len(arr)),6))
    print(round(float(len(z)/len(arr)),6))
    return round(float(len(p)/len(arr)),6), round(float(len(n)/len(arr)),6), round(float(len(z)/len(arr)),6)

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
