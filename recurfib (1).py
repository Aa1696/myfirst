# -*- coding: utf-8 -*-
"""
Created on Sun Jan 14 22:15:58 2018

@author: sharda
"""

def fib(n):
    if(n==0):
        return 0
    elif n==1:
        return 1
    else:
        return (fib(n-1)+fib(n-2))
x=int(input("any no."))
for i in range(0,x+1):
    print(fib(i))
    