#This will display one alphabet at a time
#This demonstrates the working of binary card -p '#', that how it extracts alphabets
#from each words and displays on screen as per arguments

#set color to normal
echo -e "\033[0m"
col=1

set_color()
{
  col=`expr $col + 1`
  col=`expr $col % 6`
  if [ $col -eq 0 ]; then
    col=`expr $col + 1`
  fi
  
  tput setf $col
}

#create an infinite loop.
for (( ; ; ))
do
  clear
  set_color
  src/card -p '#' -C 0 H
  sleep 0.5

  set_color
  src/card -p '#' -C 0 !A
  sleep 0.5

  set_color
  src/card -p '#' -C 0 !!P
  sleep 0.5

  set_color
  src/card -p '#' -C 0 !!!P
  sleep 0.5

  set_color
  src/card -p '#' -C 0 !!!!Y
  sleep 0.5

  set_color
  src/card -p '#' -C 0 ! B
  sleep 0.5

  set_color
  src/card -p '#' -C 0 ! !I
  sleep 0.5

  set_color
  src/card -p '#' -C 0 ! !!R
  sleep 0.5

  set_color
  src/card -p '#' -C 0 ! !!!T
  sleep 0.5

  set_color
  src/card -p '#' -C 0 ! !!!!H
  sleep 0.5

  set_color
  src/card -p '#' -C 0 ! !!!!!D
  sleep 0.5

  set_color
  src/card -p '#' -C 0 ! !!!!!!A
  sleep 0.5

  set_color
  src/card -p '#' -C 0 ! !!!!!!!Y
  sleep 0.5

done



