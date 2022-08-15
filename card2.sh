#set color to normal
echo -e "\033[0m"
col=1
index=0
#create an array of pixels
pixel=( '^' '@' '#' '$' '&' '(' ')' '{' '}' '[' ']' '<' '>' '\' '/' '|' '.' ',' '+' '-' '~' '!' )
#create an infinite loop
for (( ; ; ))
do
  #set display color.
  tput setf $col
  for ((row = 1; row < 25; row++))
  do
    src/card -r $row -p ${pixel[$index]} HAPPY
    sleep 0.08
  done

  for ((row = 1; row < 25; row++))
  do
    src/card -r $row -p ${pixel[$index]} BIRTHDAY
    sleep 0.08
  done

  col=`expr $col + 1`
  col=`expr $col % 7`
  if [ $col -eq 0 ]; then
    col=`expr $col + 1`
  fi

  index=`expr $index + 1`
  if [ $index -eq 22 ]; then
   index=0  
  fi  
  
done
