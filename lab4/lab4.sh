#!/bin/sh

if [ $# -ne 1 ]
then 
  echo "You should write ONLY a name of your program!"
  exit
fi

if ((echo "$1" | grep -Eo "^?[a-zA-Z0-9_-]+\.(c|cpp|for|f|h|C|m|ADA)$"))
then 
  error=0
else
  echo "Some errors in the name of your program!"
  exit
fi

if [ -f $1 ] && [ $error -eq 0 ]
then  
  echo "Let's start our work!"
  echo "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
  name_of_file=$1
else
  echo "You are lying! Your file doesn't exist!"
  exit
fi

number=1

for optimization in -O0 -Os -O1 -O2 -O3 "-O2 -march=native" "-O3 -march=native" "-O2 -march=native -funroll-loops" "-O3 -march=native -funroll-loops"
do
  echo "\t\t$number"
  echo "\e[33m1)CURRENT OPTION(S) OF OPTIMIZATION : \e[0m" $optimization
  gcc $optimization $name_of_file -o test1 -lm
  echo "\e[33m2)TIME : \e[0m" 
  time -p  ./test1
  echo
  echo "\e[33m3)MEMORY : \e[0m"
  echo -n "\e[4mIn bytes\e[0m"
  echo -n " - "
  du -b ./test1
  echo -n "\e[4mIn kilobytes\e[0m"
  echo -n " - "
  du -h ./test1
  rm test1
  echo "___________________________________"
  number=$(($number+1))
done

echo "\tFOR THE MOST OPTIMAL OPTIMIZATION : "
number=1

for optimization in "-fipa-reference -fipa-sra -fipa-cp -flto"\
                    "-fprofile-use=/home/alex/"\
		    "-fipa-reference -fipa-sra -fipa-cp -flto -fprofile-use=/home/alex/"
do
  echo "\t\t$number"
  echo "\e[33m1)CURRENT OPTION(S) OF OPTIMIZATION: \e[0m -O2 " $optimization
  gcc -O2 $optmization $name_of_file -o test1 -lm
  echo "\e[33m2)TIME : \e[0m"
  time -p ./test1
  echo
  echo "\e[33m3)MEMORY : \e[0m"
  echo -n "\e[4mIn bytes\e[0m"
  echo -n " - "
  du -b ./test1
  echo -n "\e[4mIn kylobytes\e[0m"
  echo -n " - "
  du -h ./test1
  rm test1
  echo "___________________________________"
  number=$(($number+1))
done
