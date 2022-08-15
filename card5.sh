
for (( ; ; ))
do
  for col in 3 2 1 4 5 6
  do
    echo -e "\033[0m"
    clear
  
    case $col in
      1)
        echo -e "\033[41m"
      ;;
 
      2)
        echo -e "\033[42m"
      ;;
 
      3)
        echo -e "\033[43m"
      ;;
 
      4)
        echo -e "\033[44m"
      ;;
 
      5)
        echo -e "\033[45m"
      ;;
 
      6)
        echo -e "\033[46m"
      ;;
 
      *) echo "wrong input"
      ;;
    esac

    src/card -d 100000 -p ' ' -C 0 HAPPY BIRTHDAY
  done
done   


