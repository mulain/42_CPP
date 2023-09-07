echo "\nTests will be run on supplied file <shmism.txt>\n"
echo "While the program will deal with error inputs, e.g. empty strings or same strings, \
the script test result may be false.\n"
read -p "Enter argument 1, the search string: " string1;
read -p "Enter argument 2, the replace string: " string2;
echo "\n"

./replace0r shmism.txt $string1 $string2

echo "Here is the content of the .result file:\n--"
cat shmism.txt.replace
echo "\n--\n"

grep -q $string1 shmism.txt.replace
var=$?
if [ $var == 0 ]
then
    echo "Fail. Target to replace was found in .replace file."
else
    echo "Success. Target to replace was not found in .replace file."
fi