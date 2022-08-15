#set color to normal
echo -e "\033[0m"
col=1;
for (( ; ; ))
do
  #set display color.
  tput setf $col
  ./src/card -f 6 -p '#' HAPPY
  sleep 0.4

  ./src/card -f 6 -p '#' !APPY H
  sleep 0.4
  ./src/card -f 6 -p '#' !APPY ! H
  sleep 0.4

  ./src/card -f 6 -p '#' !APPY 
  sleep 0.4
  ./src/card -f 6 -p '#' !!PPY !A
  sleep 0.4
  ./src/card -f 6 -p '#' !!PPY !! !A
  sleep 0.4

  ./src/card -f 6 -p '#' !!PPY 
  sleep 0.4
  ./src/card -f 6 -p '#' !!!PY !!P
  sleep 0.4
  ./src/card -f 6 -p '#' !!!PY !!! !!P
  sleep 0.4

  ./src/card -f 6 -p '#' !!!PY 
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!Y !!!P
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!Y !!!! !!!P
  sleep 0.4

  ./src/card -f 6 -p '#' !!!!Y 
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!! !!!!Y
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!! !!!!! !!!!Y
  sleep 0.4

  ./src/card -f 6 -p '#' BIRTHDAY
  sleep 0.4

  ./src/card -f 6 -p '#' !IRTHDAY B
  sleep 0.4
  ./src/card -f 6 -p '#' !IRTHDAY ! B
  sleep 0.4

  ./src/card -f 6 -p '#' !IRTHDAY 
  sleep 0.4
  ./src/card -f 6 -p '#' !!RTHDAY !I
  sleep 0.4
  ./src/card -f 6 -p '#' !!RTHDAY !! !I
  sleep 0.4

  ./src/card -f 6 -p '#' !!RTHDAY 
  sleep 0.4
  ./src/card -f 6 -p '#' !!!THDAY !!R
  sleep 0.4
  ./src/card -f 6 -p '#' !!!THDAY !!! !!R
  sleep 0.4

  ./src/card -f 6 -p '#' !!!THDAY 
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!HDAY !!!T
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!HDAY !!!! !!!T
  sleep 0.4

  ./src/card -f 6 -p '#' !!!!HDAY 
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!!DAY !!!!H
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!!DAY !!!!! !!!!H
  sleep 0.4

  ./src/card -f 6 -p '#' !!!!!DAY 
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!!!AY !!!!!D
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!!!AY !!!!!! !!!!!D
  sleep 0.4

  ./src/card -f 6 -p '#' !!!!!!AY 
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!!!!Y !!!!!!A
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!!!!Y !!!!!!! !!!!!!A
  sleep 0.4

  ./src/card -f 6 -p '#' !!!!!!!Y 
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!!!!! !!!!!!!Y
  sleep 0.4
  ./src/card -f 6 -p '#' !!!!!!!! !!!!!!!! !!!!!!!Y
  sleep 0.4

  col=`expr $col + 1`
  col=`expr $col % 6`
  if [ $col -eq 0 ]; then
    col=`expr $col + 1`
  fi

done
