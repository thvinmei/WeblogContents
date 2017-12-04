//数学問題botより勇者5000回

/*
    勇者AとモンスターBが戦う。
    BのHPは30で、Aから始めて交互に攻撃する。
    Aは捨て身でダメージ5を与えダメージ1を受ける。
    Bは出目が等確率なサイコロを振りAのHPが目の倍数ならAを即死させる。
    Aの勝つ確率が最も高い場合と低い場合のAの初期HPは幾らか。
    (nyoki1007様）
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int H,h,b,D,i,win,lose,k;

  srand((unsigned) time(NULL));

  FILE *fp,*gp;
  fp = fopen("HeroBattle.csv", "w");

  for(H=1;H<300;H++){
    win=0;
    lose=0;

    for(i=1;i<5000;i++){
      b=30; //Monster's HP.
      h=H;
      k=0;

      while(k==0){
    b=b-5;
    h=h-1;

    D=rand()%6+1;

    if(h<1){
      lose=lose+1;
      k=1;
    }
    else{
      if(b<1){
        win=win+1;
        k=1;
      }
      else{
        if(h%D==0){
          lose=lose+1;
          k=1;
        }
        else{
          k=0;
        }
      }
    }
      }
    }
    printf("HERO's HP is %d.  Win:%d.  Lose:%d\n",H,win,lose);
    fprintf(fp,"%d,%d,%d\n",H,win,lose);
  }
  fclose(fp);

  return 0;

}