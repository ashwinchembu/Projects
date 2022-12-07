# This script resets the setup, by repopulating the LinkedList directory.
#
# USAGE: ./reset.sh
#
# C. Seshadhri, Jan 2020


read -p "Are you sure? You will lose all changes in the LinkedList directory. Type Y if you wish to continue. " RESP # response of student
if [ "$RESP" = "Y" ]; then
    echo "Ok, resetting directory"
    rm LinkedList/* # delete LinkedList directory
    cp RoboGrader/AssnCode/* LinkedList # copy code files
    cp RoboGrader/Rubric/Tests/simple* LinkedList # copy test cases
else
    echo "You didn't say Y, so no change to LinkedList directory"
fi