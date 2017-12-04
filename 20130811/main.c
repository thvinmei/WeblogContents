#include <stdio.h>
//Excelの日付シリアル値を計算するプログラム
//このプログラムは1900/03/01以前の日付の計算には使えません

int main(void){
  //入力変数
  long y,n,d;
  long h,m,s;

  //基準変数
  long y_d,n_d,d_d;
  long h_d,m_d,s_d;

  //出力，計算用変数
  double sm;
  long sd,sda,sdb,sdc;
  double se;
  int np,yp;

  //以下計算対象日時の設定
  y = 2000;
  n = 1;
  d = 1;
  h = 21;
  m = 0;
  s = 0;
  printf("Input Date= %4d / %2d / %2d / %2d : %2d : %2d \n",y,n,d,h,m,s);

  //基準時刻の設定
  y_d = 1900;
  n_d = 1;
  d_d = 1;
  h_d = 0;
  m_d = 0;
  s_d = 0;
  printf("Basic Date= %4d / %2d / %2d / %2d : %2d : %2d \n",y_d,n_d,d_d,h_d,m_d,s_d);

  //シリアル値小数部分の計算
  sm = (3600 *(double)h + 60 * (double)m + (double)s)/86400;
  //printf("sm =%8.7f \n",sm); 

  //シリアル値整数部分の計算
  sda = d - d_d + 1;
  //printf("sda =%d\n",sda);

  sdb = 1;//1900年2月29日補正
  for(np=n_d;np<n;np++){
    if(np == 2){
      if(y % 400 ==0)
    sdb = sdb + 29;
      else if(y % 100 ==0){
    sdb = sdb + 28;
      }
      else if(y % 4 ==0){
    sdb = sdb + 29;      
      }
      else{
    sdb = sdb + 28;
      }
    }
    else if(np == 4|np == 6|np == 9|np == 11){
      sdb = sdb + 30;
    }
    else{
      sdb = sdb + 31;
    }
  }
  //printf("sdb =%d\n",sdb);

  sdc=0;
  for(yp = y_d;yp < y;yp++){
    if(yp % 400 == 0){
      sdc = sdc + 366;
    }
    else if(yp % 100 == 0){
      sdc = sdc + 365;
    }
    else if(yp % 4 == 0){
      sdc = sdc + 366;
    }
    else{
      sdc = sdc + 365;
    }
  }
  //printf("sdc =%d\n",sdc);

  sd = sda +sdb + sdc;
  //printf("sd =%d\n",sd);

  //シリアル値の計算
  se = sm +(double)sd;
  printf("Serial=%11.6f",se);

  return 0;
}
