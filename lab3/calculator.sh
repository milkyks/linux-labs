#!/bin/sh

if [ $# -eq 3 -o $# -gt 3 ] && [ $(($# % 2)) -eq 1 ]
then 
  if ((echo "$1" | grep -Eq "^?[0-9]+$") ||  (echo "$1" | grep -Eq "^([0-9]*\.[0-9]+)$")); 
  then
    res=$1
  else
    echo "It is not a number"
    exit
  fi
else
  echo "Not enough parameters"
  exit 
fi

shift

while [ -n "$1" ]
do
  if ((echo "$2" | grep -Eq "^?[0-9]+$") || (echo "$2" | grep -Eq "^([0-9]*\.[0-9]+)$"));
  then
    num=$2
  else
    echo "$2 is not a number!"
    exit
  fi

case $1 in
  +) res=`echo "scale=6;$res + $num" | bc`;;
  -) res=`echo "scale=6;$res - $num" | bc`;;
  /) if (([ $num = 0 ]) ||  (echo "$num" | grep -Eq "^([0]*\.[0]+)$" ));
     then 
       echo "You cant use 0 when you divide!"
       exit
     else
       res=`echo "scale=2;$res / $num" | bc`
     fi;;
   x) res=`echo "scale=2;$res * $num" | bc`;;
   *) echo "$1 is not a symbol"
      exit
esac 
shift 2
done

  echo "Result of your expression is $res"


