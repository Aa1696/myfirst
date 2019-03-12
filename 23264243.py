# cook your dish here
import math
t=int(input())
def sm_bi(a,b):
    if a<b:
        # print( 'sm',a,b)
        return a,b
    else:
        # print( 'la',a,b)
        return b,a
    
for zx in range(t):
    n_d=int(input())
    lis_pos=[int(i) for i in input().split()]
    ball_positions=[int(i) for i in input().split()]
    velocities=[int(i) for i in input().split()]
    chef_poss=[int(i) for i in input().split()]
    mins=[]
    maxs=[]
    for p in range(n_d):
        if velocities[p]==0:
            # print(111)
            continue
        else:
            a,b=(-1*ball_positions[p]/velocities[p],(lis_pos[p]-ball_positions[p])/velocities[p])
        a,b=sm_bi(a,b)
        
        mins.append(a)
        maxs.append(b)
    # print(mins,maxs)
    below_limit=max(mins)
    above_limit=min(maxs)
    
    if sum(velocities)==0:
        # print(111)
        if (sum(chef_poss)-sum(ball_positions))<0:
            t1=0
        elif (sum(chef_poss)-sum(ball_positions))>0:
            t1=math.inf
    else:
        # print(222)
        t1=(sum(chef_poss)-sum(ball_positions))/sum(velocities)
    # print(below_limit,above_limit,t1)
    if t1<below_limit:
        t1=below_limit
    else:
        if t1>above_limit:
            t1=above_limit
    # print(t1)
    arr_speed=[((ball_positions[p]-chef_poss[p])/t1)+velocities[p] for p in range(n_d)]
    speed=0
    for ar in arr_speed:
        speed+=ar**2
    speed=math.sqrt(speed)
    print(speed)
        
        

