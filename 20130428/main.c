#include <stdio.h>
//複数のCSVファイルをグラフ化させるプログラム


//自分の環境のPGNUPLOTのパスを設定 
#define GNUPLOT_PATH "C:/hogehoge/pgnuplot.exe"

//CSVファイルの格納してある場所を設定 
#define CSV_FOLDER "D:/hogehoge/CSVFOLDER"

//[CSVファイルの番号の最大値+1]の数字を設定 
#define LAST_CSV_NO 101;

int main(void){ 
  int i; 
  int END = LAST_CSV_NO;

  FILE *gp; 
  gp = _popen(GNUPLOT_PATH,"w");

  fprintf(gp,"reset\n"); 
  fprintf(gp,"%S\n",CSV_FOLDER); 
  fprintf(gp,"set datafile separator \",\"\n ");

  for(i=1 ;i<END ;i++){ 
    printf("Drawing %d.csv.\n",i);

    fprintf(gp,"set term win\n"); 
    fprintf(gp,"plot \"%d.csv\" using 1:2 \n",i); 
    fprintf(gp,"set term png\n"); 
    fprintf(gp,"set output \"Graph_%d.png\"\n",i); 
    fprintf(gp,"replot\n");

    fprintf(gp,"set term win\n"); 
    fprintf(gp,"plot[0:4][-0.05:0.45]  \"%d.csv\" using 1:2 \n",i); 
    fprintf(gp,"set term png\n"); 
    fprintf(gp,"set output \"Graph4s_%d.png\"\n",i); 
    fprintf(gp,"replot\n"); 
  }

  fprintf(gp,"set term win\n"); 
  fprintf(gp,"set output\n"); 
  _pclose(gp);

  return 0; 
} 