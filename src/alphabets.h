#ifndef ALPHABETS_H
#define ALPHABETS_H

#define DEFAULT_FONT_SIZE 8
#define DEFAULT_PIXEL 0
#define DEFAULT_PIXEL_SLEEP 0
#define DEFAULT_ALPHABET_SLEEP 0
#define DEFAULT_CLEAR_SCREEN 1

#define HALF_FRAME (font_size / 2) - 1 
#define FULL_FRAME font_size - 1 
#define HALF_LENGTH font_size / 2
#define FULL_LENGTH font_size

typedef void (*funcptr) (int row, int col, char ch);

extern char pixel;
extern int font_size; 
extern int pixel_sleep;
extern int alphabet_sleep;
extern int clear_screen;
extern inline void gotoxy(int x, int y);

#endif
