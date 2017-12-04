//特に意味はないランダムウォーク

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define path "C:/PROGRA~1/gnuplot/bin/pgnuplot.exe"

double frand(void);
double grand(void);
int move(double rand);

int main(void){
  //時刻と位置の変数
  int t,tl,ts;
  int p,q;
  int zero;

  //乱数変数
  double urn;

  //時刻と位置の最大値
  int t_max = 1000;
  int p_max = 100;
  int p_min = 0;

  //出力先
  FILE *fp;
  fp = fopen("randomwalk.dat","w");

  FILE *gp;
  gp= _popen(path,"w");

  //位置の初期設定
  p = (p_max-p_min)/2 + p_min;
  q = p;
  zero = p;

  //ランダムウォーク
  for(t=0;t<t_max;t++){
    urn = frand();
    p = p + move(urn);

    urn = grand();
    q = q + move(urn);

    if(p>p_max){
      p = zero;
    }else if(p<p_min){
      p = zero;
    }

    if(q>p_max){
      q = zero;
    }else if(q<p_min){
      q = zero;
    }

    fprintf(fp,"%d %d %d\n",t,p,q);
  }

  fclose(fp);

  //ここから画像出力
  //初期設定
  fprintf(gp,"reset\n");
  fprintf(gp,"set terminal png\n");
  fprintf(gp,"set yrange[%d:%d]\n",p_min,p_max);
  fprintf(gp,"set xrange [0:%d]\n",t_max);
  //fprintf(gp,"pause 0.1\n");

  for(t=1;t<t_max;t++){
    tl = t +19;
    ts = t -19;

    if(tl>t_max){
      tl = t_max;
    }else if(ts<0){
      ts = 1;
      tl = 38;
    }
    printf("Drawing line:%d\n",t);
    fprintf(gp,"set output 'rp%d.png'\n",t);
    //fprintf(gp,"pause 0.1\n");
    fprintf(gp,"plot 'randomwalk.dat' using 1:2 every ::::%d with lines,",t);
    fprintf(gp,"'randomwalk.dat' using 1:3 every ::::%d with lines\n",t);
    //fprintf(gp,"pause 0.1\n");
  }

  fprintf(gp,"reset\n");
  fprintf(gp,"exit\n");

  fclose(gp);

  return 0;
}

double frand(void){
  return ((double)rand()/((double)RAND_MAX));
}

double grand(void){
  return ((double)rand()+1.0)/((double)RAND_MAX+2.0);
}

int move(double rand){
  int pmove=0;

  if(rand<0.5){
    pmove = 1;
  } else if(rand>0.5){
    pmove = -1;
  } else {
    pmove = 0;
  }

  if((unsigned)time(NULL)%2==0){
    pmove = 2 * pmove;
  }else if((unsigned)time(NULL)%3==0){
    pmove = 3 * pmove;
  }

  return pmove;
}