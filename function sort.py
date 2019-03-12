# -*- coding: utf-8 -*-
"""
Created on Tue Jan 16 23:02:25 2018

@author: HP
"""

def insertion (list):
    for i in range(1,len(list)):
        key=list[i]
        j=i-1
        while(j>=0):
            if(key<list[j]):
                list[j+1]=list[j]
                list[j]=key
                j-=1
            else:
                break
a=[9,8,7,6,5,5,4,3,2,1]
insertion(a)
print(a)