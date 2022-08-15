#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "alphabets.h"

//Global variables
int i;
char pixel = DEFAULT_PIXEL;
int font_size = DEFAULT_FONT_SIZE;
int pixel_sleep = DEFAULT_PIXEL_SLEEP;
int alphabet_sleep = DEFAULT_ALPHABET_SLEEP;
int clear_screen = DEFAULT_CLEAR_SCREEN;

/*--------------------------------------------------------------------------
Macro to draw a vertical line. This will draw pixel (given character 'ch') 
at given 'row' and 'col' upto 'count' times with sleep time as specified 
by 'pixel_sleep'.

For Eg. VLINE(1, 1, 'A', 5) will draw a vertical line as:
A
A
A
A
A
------------------------------------------------------------------------*/

#define VLINE(row, col, ch, count){\
 for(i = 0; i < count; i++)\
 {\
   gotoxy(row + i, col);\
   printf("%c\n", ch);\
   usleep(pixel_sleep);\
 }\
}


/*----------------------------------------------------------------------------
Macro to draw a Horizonatl line. This will draw pixel (given character 'ch') 
at given 'row' and 'col' upto 'count' times with sleep time as specified
by 'pixel_sleep'.

For Eg. HLINE(1, 1, 'A', 5) will draw a horizontal line as:
AAAAA
---------------------------------------------------------------------------*/

#define HLINE(row, col, ch, count){\
 for(i = 0; i < count; i++)\
 {\
   gotoxy(row, col + i);\
   printf("%c\n", ch);\
   usleep(pixel_sleep);\
 }\
}


/*-------------------------------------------------------------------------
Macro to draw a Forward line(/). This will draw pixel (given character 'ch') 
at given 'row' and 'col' upto 'count' times with sleep time as specified
by 'pixel_sleep'.

For Eg. FLINE(1, 1, 'A', 5) will draw a forward line(/) as:
    A
   A
  A
 A
A
-------------------------------------------------------------------------*/

#define FLINE(row, col, ch, count){\
 for(i = 0; i < count; i++)\
 {\
   gotoxy(row + i, col - i);\
   printf("%c\n", ch);\
   usleep(pixel_sleep);\
 }\
}


/*--------------------------------------------------------------------------
Macro to draw a Back line (\). This will draw pixel (given character 'ch') 
at given 'row' and 'col' upto 'count' times with sleep time as specified
by 'pixel_sleep'.

For Eg. FLINE(1, 1, 'A', 5) will draw a Back line (\) as:
A
 A 
  A
   A
    A
-------------------------------------------------------------------------*/

#define BLINE(row, col, ch, count){\
 for(i = 0; i < count; i++)\
 {\
   gotoxy(row + i, col + i);\
   printf("%c\n", ch);\
   usleep(pixel_sleep);\
 }\
}


/*-------------------------------------------
Function to move cursor to given row(x)
and column(y). 

-------------------------------------------*/

inline void gotoxy(int x, int y)
{
  //The only line copied from net :)
  printf("%c[%d;%df",0x1B,x,y);
}


/*------------------------------------------------------
Function to draw alphabet A.

------------------------------------------------------*/

void A(int row, int col, char ch)
{
  if(!ch)
    ch = 'A';
  FLINE(row, col + HALF_FRAME, ch, HALF_LENGTH);
  VLINE(row + HALF_FRAME + 1, col, ch, HALF_LENGTH);
  BLINE(row, col + HALF_FRAME + 1, ch, HALF_LENGTH);
  VLINE(row + HALF_FRAME + 1, col + FULL_FRAME, ch, HALF_LENGTH);
  HLINE(row + HALF_FRAME + 1, col, ch, FULL_LENGTH);
}


/*------------------------------------------------------
Function to draw alphabet B.

------------------------------------------------------*/

void B(int row, int col, char ch)
{
  if(!ch)
    ch = 'B';
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row, col , ch, FULL_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, HALF_LENGTH);
  HLINE(row + HALF_FRAME, col, ch, FULL_LENGTH);
  VLINE(row + HALF_FRAME, col + FULL_FRAME, ch, HALF_LENGTH);
  HLINE(row + FULL_FRAME, col, ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet C.

------------------------------------------------------*/

void C(int row, int col, char ch)
{
  if(!ch)
    ch = 'C';
  HLINE(row, col, ch, FULL_LENGTH);
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row + FULL_FRAME, col , ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet D.

------------------------------------------------------*/

void D(int row, int col, char ch)
{
  if(!ch)
    ch = 'D';
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row, col , ch, FULL_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
  HLINE(row + FULL_FRAME, col , ch, FULL_LENGTH);
}


/*------------------------------------------------------
Function to draw alphabet E.

------------------------------------------------------*/

void E(int row, int col, char ch)
{
  if(!ch)
    ch = 'E';
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row, col , ch, FULL_LENGTH);
  HLINE(row + HALF_FRAME, col , ch, HALF_LENGTH);
  HLINE(row + FULL_FRAME, col , ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet F.

------------------------------------------------------*/

void F(int row, int col, char ch)
{
  if(!ch)
    ch = 'F';
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row, col , ch, FULL_LENGTH);
  HLINE(row + HALF_FRAME, col , ch, HALF_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet G.

------------------------------------------------------*/

void G(int row, int col, char ch)
{
  if(!ch)
    ch = 'G';
  HLINE(row, col, ch, FULL_LENGTH);
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row + FULL_FRAME, col , ch, FULL_LENGTH);
  VLINE(row + HALF_FRAME, col + FULL_FRAME, ch, HALF_LENGTH);
  HLINE(row + HALF_FRAME, col + HALF_FRAME, ch, HALF_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet H.

------------------------------------------------------*/

void H(int row, int col, char ch)
{
  if(!ch)
    ch = 'H';
  VLINE(row, col, ch, FULL_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
  HLINE(row + HALF_FRAME, col, ch, FULL_LENGTH);
}


/*------------------------------------------------------
Function to draw alphabet I.

------------------------------------------------------*/

void I(int row, int col, char ch)
{
  if(!ch)
    ch = 'I';
  VLINE(row, col + HALF_FRAME, ch, FULL_LENGTH);
  HLINE(row, col, ch, FULL_LENGTH);
  HLINE(row + FULL_FRAME, col, ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet J.

------------------------------------------------------*/

void J(int row, int col, char ch)
{
  if(!ch)
    ch = 'J';
  VLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
  HLINE(row + FULL_FRAME, col , ch, FULL_LENGTH);
  VLINE(row + HALF_FRAME, col, ch, HALF_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet K.

------------------------------------------------------*/

void K(int row, int col, char ch)
{
  if(!ch)
    ch = 'K';
  VLINE(row, col, ch, FULL_LENGTH);
  FLINE(row, col + HALF_FRAME, ch, HALF_LENGTH);
  BLINE(row + HALF_FRAME, col, ch, HALF_LENGTH);
  
}

/*------------------------------------------------------
Function to draw alphabet L.

------------------------------------------------------*/

void L(int row, int col, char ch)
{
  if(!ch)
    ch = 'L';
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row + FULL_FRAME, col , ch, FULL_LENGTH);
}


/*------------------------------------------------------
Function to draw alphabet M.

------------------------------------------------------*/

void M(int row, int col, char ch)
{
  if(!ch)
    ch = 'M';
  VLINE(row, col, ch, FULL_LENGTH);
  BLINE(row, col, ch, HALF_LENGTH);
  FLINE(row, col + FULL_FRAME, ch, HALF_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet N.

------------------------------------------------------*/

void N(int row, int col, char ch)
{
  if(!ch)
    ch = 'N';
  VLINE(row, col, ch, FULL_LENGTH);
  BLINE(row, col, ch, FULL_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet O.

------------------------------------------------------*/

void O(int row, int col, char ch)
{
  if(!ch)
    ch = 'O';
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row, col , ch, FULL_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
  HLINE(row + FULL_FRAME, col , ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet P.

------------------------------------------------------*/

void P(int row, int col, char ch)
{
  if(!ch)
    ch = 'P';
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row, col , ch, FULL_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, HALF_LENGTH);
  HLINE(row + HALF_FRAME, col, ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet Q.

------------------------------------------------------*/

void Q(int row, int col, char ch)
{
  if(!ch)
    ch = 'Q';
  HLINE(row, col , ch, FULL_LENGTH);
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row + FULL_FRAME, col , ch, FULL_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
  BLINE(row + HALF_FRAME, col + HALF_FRAME, ch, HALF_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet R.

------------------------------------------------------*/

void R(int row, int col, char ch)
{
  if(!ch)
   ch = 'R';
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row, col , ch, FULL_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, HALF_LENGTH);
  HLINE(row + HALF_FRAME, col, ch, FULL_LENGTH);
  BLINE(row + HALF_FRAME + 1, col + HALF_FRAME, ch, HALF_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet S.

------------------------------------------------------*/

void S(int row, int col, char ch)
{
  if(!ch)
    ch = 'S';
  HLINE(row, col , ch, FULL_LENGTH);
  VLINE(row, col, ch, HALF_LENGTH);
  HLINE(row + HALF_FRAME, col , ch, FULL_LENGTH);
  VLINE(row + HALF_FRAME, col + FULL_FRAME, ch, HALF_LENGTH);
  HLINE(row + FULL_FRAME, col, ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet T.

------------------------------------------------------*/

void T(int row, int col, char ch)
{
  if(!ch)
    ch = 'T';
  HLINE(row, col , ch, FULL_LENGTH);
  VLINE(row, col + HALF_FRAME, ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet U.

------------------------------------------------------*/

void U(int row, int col, char ch)
{
  if(!ch)
    ch = 'U';
  VLINE(row, col, ch, FULL_LENGTH);
  HLINE(row + FULL_FRAME, col , ch, FULL_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet V.

------------------------------------------------------*/

void V(int row, int col, char ch)
{
  if(!ch)
    ch = 'V';
  VLINE(row, col, ch, HALF_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, HALF_LENGTH);
  BLINE(row + HALF_FRAME, col, ch, HALF_LENGTH);
  FLINE(row + HALF_FRAME, col + FULL_FRAME, ch, HALF_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet W.

------------------------------------------------------*/

void W(int row, int col, char ch)
{
  if(!ch)
    ch = 'W';
  VLINE(row, col, ch, FULL_LENGTH);
  FLINE(row + HALF_FRAME, col + HALF_FRAME, ch, HALF_LENGTH);
  BLINE(row + HALF_FRAME, col + HALF_FRAME, ch, HALF_LENGTH);
  VLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet X.

------------------------------------------------------*/

void X(int row, int col, char ch)
{
  if(!ch)
    ch = 'X';
  BLINE(row, col, ch, FULL_LENGTH);
  FLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet Y.

------------------------------------------------------*/

void Y(int row, int col, char ch)
{
  if(!ch)
    ch = 'Y';
  BLINE(row, col, ch, HALF_LENGTH);
  FLINE(row, col + FULL_FRAME, ch, HALF_LENGTH);
  VLINE(row + HALF_FRAME + 1, col + HALF_FRAME, ch, HALF_LENGTH);
}

/*------------------------------------------------------
Function to draw alphabet Z.

------------------------------------------------------*/

void Z(int row, int col, char ch)
{
  if(!ch)
    ch = 'Z';
  HLINE(row, col , ch, FULL_LENGTH);
  FLINE(row, col + FULL_FRAME, ch, FULL_LENGTH);
  HLINE(row + FULL_FRAME, col, ch, FULL_LENGTH);
}

//TODO
/*------------------------------------------------------
Function to draw digits 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
currently no time :), will support in future.
------------------------------------------------------*/

//Array of function pointers holding address of all functions
funcptr func_handler[26] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

