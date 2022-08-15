#set color to normal
echo -e "\033[0m"
col=1
#create an infinite loop.
for ((;;))
do
  #change pixels in each message. For Eg. First time pixel will be '#', 
  #second time pixel will be 'H', third time pixel will 'A' and so on..
  #changing of pixels will create message "#HAPPYB'DAY".
  for pixel in '#' H A P P Y B \' D A Y 
  do
    #set display color.
    tput setf $col
    #create zoom in effect by increasing font size.
    for ((i=6; i<10; i+=2))
    do
      src/card -f $i -p $pixel HAPPY BIRTHDAY
      sleep 0.4
    done
    #create zoom out effect by decreasing font size.
    for ((i=10; i>6; i-=2))
    do
      src/card -f $i -p $pixel HAPPY BIRTHDAY
      sleep 0.4
    done
    col=`expr $col + 1`
    col=`expr $col % 6`
    if [ $col -eq 0 ]; then
      col=`expr $col + 1`
    fi
  done
done
