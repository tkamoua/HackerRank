#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxSubsetSum function below.
#Steps
#1. Base cases:if len(arr) == 0, return 0
#2. Recursion: return max(mss(arr[:-2]+arr[-1], mss(arr[:-1])) )
def maxSubsetSum(arr):
    memo = [-1]*(len(arr)+1)
    if len(arr) >= 0:
        memo[0] = 0
    if len(arr) >= 1:
        memo[1] = max(0,arr[0])
    if len(arr) >= 2:
        memo[2] = max(0,max(arr[0],arr[1]))
    for i in range(2,len(arr)+1):
        memo[i] = max(memo[i-2]+arr[i-1],memo[i-1])
    return memo[len(arr)]
    #return returnOutput(arr,memo)

def returnOutput(arr,memo):
    if len(arr) <= 0:
        return 0
    if len(arr) == 1:
        return max(0,arr[0])
    if len(arr) == 2:
        return max(0,max(arr[0],arr[1]))
    else:
        if memo[len(arr)] >= 0:
            return memo[len(arr)]
        else:
            memo[len(arr)] = max(returnOutput(arr[:-2],memo)+arr[-1],returnOutput(arr[:-1],memo))
            return memo[len(arr)]
        #return max(returnOutput(arr[:-2])+arr[-1],returnOutput(arr[:-1]))
   
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = maxSubsetSum(arr)

    fptr.write(str(res) + '\n')

    fptr.close()