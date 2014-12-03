echo "Running unit tests:"
echo "------"

for i in tests/*_tests
do
  if test -f $i
  then
    if $VALGRIND ./$i
    then
      echo $i PASS
    else
      exit 1
    fi
  fi
done

echo ""
