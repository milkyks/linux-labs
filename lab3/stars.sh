#!/bin/sh

if ((echo "$1" | grep -Eq "^?[0-9]+$")) 
then 
  if [ $(($1 % 2)) -eq 1 ]  
  then 
    number=$1
  else
    echo "Your number is even!"
    exit
  fi  
else
  echo "You should write an integer number!"
  exit
fi     

amount_of_spaces=$(($number-1))
amount_of_stars=0
stars="* "

while [ $amount_of_stars -lt $number ]
do
  for j in $(seq 1 $amount_of_spaces)
  do
    echo -n " ";  
  done

  amount_of_spaces=$(($amount_of_spaces-1))
        
  for j in $(seq 0 $amount_of_stars)
  do	
    echo -n "$stars";
  done

  echo 

  amount_of_stars=$(($amount_of_stars+1))
done
	
amount_of_spaces=$(($number-1))
all_spaces=$(($number-1))
amount_of_stars=$(($number-1))

while [ $amount_of_stars -gt 0 ]
do
  for j in $(seq $amount_of_spaces $all_spaces)
  do
    echo -n " "
  done 

  amount_of_spaces=$(($amount_of_spaces-1))

  for j in $(seq 1 $amount_of_stars)
  do
    echo -n "$stars"
  done

  echo
 
  amount_of_stars=$(($amount_of_stars-1))
done

