# -*- coding: utf-8 -*-
"""
ラジオ音源にパーソナリティを書き込むスクリプト
"""
 
from mutagen.id3 import ID3, TALB, TPE1, TRCK, TCON
from mutagen.mp3 import MP3
import mutagen.id3
import glob

if __name__ == '__main__':
    files = glob.glob('FILEDIRECTORY/*') #ファイルの保存されたディレクトリ名を入れる
    
    with open("PERSONALITY.txt") as artfile: #各回のパーソナリティが1行ごとに書かれたテキスト
    artist = artfile.readlines()
    
    for track in range(len(files)):
    mp3 = MP3(files[track],ID3=ID3)
    mp3["TPE1"] = TPE1(encoding=3, text=artist[track]) #パーソナリティを書き込み
    mp3["TALB"] = TALB(encoding=3, text='RADIOTITLE') #番組名の書き込み
    mp3['TCON'] = TCON(encoding=3, text='GENRE') #ジャンル書き込み
    mp3["TRCK"] = TRCK(encoding=3, text=[str(track + 1)]) #トラック番号(放送回次)を書き込み
    mp3.save()