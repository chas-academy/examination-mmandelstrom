echo "Running tests..."
#echo

result=$(echo -e "adam 8 8 8 8 8 8 8 8 8 8 8 8 8 eve 7 9 7 9 8 6 10 8 7 8 9 8 7 bob 5 6 5 6 5 6 5 6 5 6 5 6 7 Dave 7 7 7 7 7 7 7 6 6 6 6 6 6 Charlie 9 9 9 9 9 9 7 7 10 10 10 10 10" | ./main.out)

# Read the resulting values into an array
readarray -t values <<< "$result"

# How many values did we get
array_length=${#values[@]}

# Assign each value to a variable
best_name=${values[0]}
need_help1=${values[1]}
need_help2=${values[2]}

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

if [ "$array_length" == "3" ] ; then
  echo "Pass: Expected '3' names and got $array_length names"
else
  echo "Expected '3' names but got: $best_name names"
  exit 1
fi

if [ "$best_name" == "Charlie" ] ; then
  echo "Pass: Expected 'Charlie' and got $best_name"
else
  echo "Expected 'Charlie' but got: $best_name"
  exit 1
fi

if [ "$need_help1" == "Bob" ] ; then
  echo "Pass: Expected 'Bob' and got: $need_help1"
else
  echo "Expected 'Bob' but got: $need_help1"
  exit 1
fi

if [ "$need_help2" == "Dave" ] ; then
  echo "Pass: Expected 'Dave' and got: $need_help2"
else
  echo "Expected 'Dave' but got: $need_help2"
  exit 1
fi

echo
echo "All tests passed."
exit 0
