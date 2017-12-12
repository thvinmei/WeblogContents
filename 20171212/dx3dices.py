# -*- coding: utf-8 -*-
"""
Spyderエディタ

これは一時的なスクリプトファイルです
"""

import numpy as np
import matplotlib.pyplot as plt

if __name__ == '__main__':
    print("ダイス数を入力")
    dices       = int(input())
    print("クリティカル値を入力")
    critical    = int(input())
    trials      = 10000
    
    score = np.zeros(trials)
   
    for num in range(trials):
        loops       = 0
        score[num]  = 0  
        dice = dices
    
        while(dice>0):
            droll = np.random.randint(1,11,dice)
            
            ##ファンブルのチェック(初回のみ)
            if (loops == 0 and np.sum(droll) == dice):
                print("ファンブル")
                break
            ##クリティカルチェック(毎回)
            cdice = np.where(droll >= critical)
            if len(cdice) > 0 :
                loops = loops + 1
                dice = len(cdice[0])
            else:
                break
            
        score[num] = loops * 10 + max(droll)
    
    ##スコア平均の計算
    print("ダイスロール平均値"+str(np.average(score)))
    plt.hist(score,range=(0,100),bins=10,normed=True)
    plt.show()