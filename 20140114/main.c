//TeXの1ptとWordの1ptは違う．そんなことが『LaTeX 2ε 美文書作成入門』に書かれてたので，変換プログラムを書いてみるなど．

#include <stdio.h>

double WtoT(double w);
double TtoW(double t);

int main(void){
  double word;
  double tex;
  double space;

  scanf("%lf",&word);

  tex = WtoT(word);

  space = tex * 1.5;

  printf("Word:%5.3f = TeX:%5.3f\n",word,tex);
  printf("\\fontsize{%5.3fpt}{%5.3fpt}\\selectfont\n",tex,space);

  return 0;
}

double WtoT(double w){
  double inch;
  double t;
  inch = w / 72;
  t = inch * 72.27 ;
  return t;
}

double TtoW(double t){
  double inch;
  double w;
  inch = t /72.27;
  w = inch * 72;
  return w;
}