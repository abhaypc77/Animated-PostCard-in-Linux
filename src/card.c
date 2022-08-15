#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "alphabets.h"


extern funcptr func_handler[];
int row = 2, col = 2;

/*----------------------------------------------------
Function to display the usage.

----------------------------------------------------*/

inline void usage(char *binary_name)
{
  fprintf(stderr, "Usage  :\n");
  fprintf(stderr, "%s -r <row> -c <column> -p <pixel> -d <pixel delay> -D <alphabet delay> -f <font_size> 'Message'\n", binary_name);
  fprintf(stderr, "   -r  : Row from which alphabets to be drawn.\n");
  fprintf(stderr, "   -c  : Column from which alphabets to be drawn.\n");
  fprintf(stderr, "   -p  : Pixel which is to be drawn on screen.\n");
  fprintf(stderr, "   -d  : Delay between two consecutive pixels.\n");
  fprintf(stderr, "   -d  : Delay between two consecutive Alphabets.\n");
  fprintf(stderr, "   -f  : font size of the alphabet which is to be drawn on screen.\n");
  fprintf(stderr, "   -C  : Clear the screen before displaying Message.\n");
  fprintf(stderr, "Message: Message which is to be displayed.\n\n");
  exit(-1);
}


/*---------------------------------------------------------------------
Function to parse all command line arguments. This will parse
1. Row.
2. Column.
3. pixel to be displayed on screen.
4. Delay between two consecutive pixels.
5. Delay between two consecutive Alphabets.
6. font size of the alphabet.
7. Clear the screen.

This function will return the index of non-option argument which 
are passed through command line.
For Ex. './card -r 1 -c 1 hello world' 
this function will return the index of 'hello'
-------------------------------------------------------------------*/

int parse_arguments(int argc, char **argv)
{
  char option;

  while((option = getopt(argc, argv, "r:c:p:d:D:f:C:")) != -1)
  {
    switch (option)
    {
      case 'r':
        row = atoi(optarg);
        break;

      case 'c':
        col = atoi(optarg);
        break;

      case 'p':
        pixel = optarg[0];
        break;

      case 'd':
        pixel_sleep = atoi(optarg);
        break;

      case 'D':
        alphabet_sleep = atoi(optarg);
        break;

      case 'f':
        font_size = atoi(optarg);
        //font_size less than 4 are accepted
        if(font_size <= 4)
          font_size = 4;
        //convert font_size to even number
        if(font_size % 2 == 1) 
          font_size++;
          
        break;

      case 'C':
        clear_screen = atoi(optarg);
        break;

      default:
        printf("Error: Invalid arguments.\n");
        usage(argv[0]);
    }
  }
  
  //return index of non-option arguments
  return optind;
}


/*--------------------------------------------------------------------
main function of the program.

--------------------------------------------------------------------*/

int main(int argc, char **argv)
{
  char *text_ptr;
  int index;

  if(argc < 2)
    usage(argv[0]);
 
  //parse command line options and store start index of text which is to be displayed
  index = parse_arguments(argc, argv);

  //clear the screen
  if(clear_screen)
    system("clear");

  //If no message is given after the options
  if(index == argc)
    usage(argv[0]);  

  //Display all the words starting from index to argument count (argc)
  for( ; index < argc; index++)
  {
    text_ptr = argv[index];
    while(*text_ptr)
    { 
      //Check if character is alphabet or not
      if(isalpha(*text_ptr)) {
        //If alphabet convert to upper case 
        //Find index of function pointer in array of function pointer and pass row, column and pixel to be displayed
        //For Eg. If character is 'A' ascii value 65 then index will be 65 - 65 = 0
        // If character is 'B' ascii value 66 then index will be 66 - 65 = 1
        func_handler[(toupper(*text_ptr)) - 65] (row-1, col-1, pixel);
      }
      col += font_size + 5;
      text_ptr++;
      sleep(alphabet_sleep);
    }
    
    row += font_size + 5;
    col = 1;
    
  }
  
  //row -= font_size + 5;
  //col = 1;
  gotoxy(row, col);
  printf("\n");

  return 0;

}
