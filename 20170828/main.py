# -*- coding: utf-8 -*-
"""
Created on Mon Aug 28 21:23:12 2017
@author: vinmei
ネタ元
Hiroshi Saito @spiral_world
「同じサイコロを２回投げて同じ目が出る確率は？ ただし、そのサイコロを投げた時の各目が出る確率の分布は不明であるが、試行毎に確率分布の変動は起きず、なおかつ各試行は独立であるものとする。」
https://twitter.com/spiral_world/status/901713682484289537
"""

import random
import numpy as np

if __name__ == '__main__':
    #--------Setting-------------------------------------
    N = 6 #ダイスの面数
    DiceRollTraials = 7500 #ダイスを変更せずに振る回数
    TraialSet = 20 #ダイスを変更して降ってみる回数
    RANDOM_DICE = True #出目に偏りのあるダイスを使うか否か
    #----------------------------------------------------
   
    Dice = 2 #ダイスの個数(2固定)
    Pn = np.zeros(N)
    PPn = np.zeros(N)
    DRp = np.zeros(Dice)
    DR = np.zeros(Dice)
    DO = np.zeros((N,N))
    
    ## make random dice
    if RANDOM_DICE:
        for i in range(0,N):
            Pn[i] = random.random()
        
        Pn = Pn / sum(Pn)
        
        for i in range(0,N):
            if i != 0:
                PPn[i] = Pn[i] + PPn[i-1]
            else:
                PPn[i] = 0.0
    else: # Normal Dice
        PPn = np.array([0,1/6,2/6,3/6,4/6,5/6])
    
    ## Dice Rool Loop
    for ts in range(TraialSet):
        cp = 0
        for row in range(DiceRollTraials):
            
            DRp = np.sort(np.random.rand(Dice))    
        
            for d in range(Dice):
                for i in range(N):
                    if DRp[d] < PPn[i]:
                        DR[d] = DR[d]
                    else:
                        DR[d] = i
                    
            DO[int(DR[0]),int(DR[1])] = DO[int(DR[0]),int(DR[1])] + 1
        
        DO = DO / DO.sum()
       
        for i in range(N):
            cp = DO[i,i] + cp
                            
        print(cp)