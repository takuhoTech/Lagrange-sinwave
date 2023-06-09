#include <stdio.h>
#include <stdlib.h>
#include "API.c"

#define nTH 9

struct color white = { 255, 255, 255 };
struct color black = { 0, 0, 0 };
struct color red = { 255, 0, 0 };

/* Lagrange Three point Interpolation */

int main ( int argc, char **argv ) {
  double x, f;
  double X[nTH];
  double F[nTH];

  for(int n = 0; n < nTH; n++)
  {
    printf("X[%d] F[%d]> ", n, n);
    scanf( "%lf %lf", &X[n], &F[n] );
  }

  img_clear();

  for (x = 0; x<= 15; x+=0.1) {
    
    img_putpixel(red, x*10, (sin(x)*10+(PIXEL/2)));
  }

  for(int tmp = 1;tmp<=PIXEL;tmp++)
  {
    img_putpixel(black, tmp, PIXEL/2);
  }
  //printf( "x for f(x)> " );
  //while ( scanf( "%lf", &x ) != EOF ) {		/* ファイルの終りまでを行ごとに処理する決まり文句 */
  for (x = 0; x<= 15; x+=0.1) {
    /*f = (       (x-X[1])*(x-X[2]))/(        (X[0]-X[1])*(X[0]-X[2])) * F[0]
      + ((x-X[0])       *(x-X[2]))/((X[1]-X[0])        *(X[1]-X[2])) * F[1]
      + ((x-X[0])*(x-X[1])       )/((X[2]-X[0])*(X[2]-X[1])        ) * F[2];*/
      f = 0;
    for(int j = 0; j < nTH; j++)
    {
        double top = 1, bottom = 1;
        for(int i = 0; i < nTH; i++)
        {
            if(i != j)
            {
                top *= x - X[i];
                bottom *= X[j]-X[i];
            }
        }
        f += (top/bottom)*F[j];
    }
    //printf( "f(%lf) = %lf\n", x, f );
    //printf( "x for f(x)> " );
    
    img_putpixel(black, x*10, (f*10+(PIXEL/2)));
  }
  //printf( "\n" );
  img_write();
  return 0;
}