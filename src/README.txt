card:

This is a generic program to display the message in a card form. Things which are not covered(TODOs) due to lack of time are covered through 
shell script wrappers.
 

Install:

  make clean
  make build


Usage:

./card -r <row> -c <column> -p <pixel> -d <pixel delay> -D <alphabet delay> -f <font_size> 'Message'
   -r  : Row from which alphabets to be drawn.
   -c  : Column from which alphabets to be drawn.
   -p  : Pixel which is to be drawn on screen.
   -d  : Delay between two consecutive pixels.
   -d  : Delay between two consecutive Alphabets.
   -f  : font size of the alphabet which is to be drawn on screen.
   -C  : Clear the screen before displaying Message.
Message: Message which is to be displayed.



TODO(To be done in future):

1. Need to work on MAX_ROWS and MAX_COLUMNS of screen. It is a major Bug if row and col passed to draw an alphabet exceeds the 
value of MAX_ROWS and MAX_COLUMNS. 

2. Convert pixel(character) to strings. currrently we are displaying only a single character(pixel) while drawing an alphabet. 
For Eg. card -p '#' A , will display

   ##
  #  #
 #    #
########
#      #
#      #
#      #

If we pass a string instead of a single character. 
For Eg. card -p "()" A , will display


   ()()
  ()  ()
 ()    ()
()()()()()
()      ()
()      ()
()      ()
     
For Eg. card -p "abc" A , will display


   abcabc
  abc  abc
 abc    abc
abcabcabcabc
abc      abc
abc      abc
abc      abc


3. Take an extra argument to set colors of pixels and alphabets and remove 'tput setf' from shell script wrappers.


