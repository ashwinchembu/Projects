# script to automatically grade the LinkedList test.
# This script is available to students.
#
# C. Seshadhri, Jan 2020

cd RoboGrader
cp Rubric/Tests/simple* ~/workspace/LinkedList
python3 robograder.py -c -e LinkedList ~/workspace # simple running robograder

score=$( tail -n 1 ~/workspace/LinkedList/LinkedList.log )
echo ---------------------
echo Score is "$score"
echo --------------------
# Show json based passed environment
# echo $CODIO_AUTOGRADE_ENV
# Send the grade back to Codio
# curl --retry 3 -s "$CODIO_AUTOGRADE_URL&grade=$score"

cd ~ # return to main directory

