#!/bin/python3

import math
import os
import random
import re
import sys
import string

# Complete the abbreviation function below.
#Return 1 if len(a) and len(b) == 0
# else,
# if last character of each is the same, remove last character of each
# if uppercased last characteer of each is the same, remove last character of each
# else, remove last character of a

def abbreviation(a, b):
    #a = "bBccC"
    #b = "BBC"
    #memo = [[-1]*(len(b)+1)]*(len(a)+1)
    
    out =  output(a,b)
    if out:
        return "YES"
    else:
        return "NO"

def output(a,b):
    
    memo = [[-1]*(len(b)+1) for _ in range(len(a)+1)]
    for i in range(len(a)+1):
        for j in range(len(b)+1):
            #i = modify string index
            #j = target string index
            #base cases
            if i == 0 and j == 0:
                print(memo[i][j])
                memo[i][j] = True
                
           
            elif i == 0 and j != 0:
                memo[i][j] = False
               
            elif i != 0 and j == 0:
                if a[:i].islower():
                    
                    memo[i][j] = True
                else:
                    memo[i][j] = False
            #Iterations 
            else:
                
                if a[i-1] == b[j-1]:
                    memo[i][j] = memo[i-1][j-1]
                elif a[i-1].upper() == b[j-1]:
                    memo[i][j] =  memo[i-1][j-1] or memo[i-1][j]
                elif a[i-1].isupper():
                    memo[i][j] = False
                else:
                    memo[i][j] = memo[i-1][j]
    print(memo)
    return memo[len(a)][len(b)]      
                


    
    
if __name__ == '__main__':
    sys.setrecursionlimit(2000)
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        a = input()

        b = input()

        result = abbreviation(a, b)

        fptr.write(result + '\n')

    fptr.close()
