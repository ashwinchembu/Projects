## README for LinkedList section test: reverse function ##

Japheth Frolick, Aug 2019
C. Seshadhri, Jan 2020, Oct 2020

### The reverse function ###

The folder LinkedList contains a standard implementation of a linked list, with a wrapper to run it.
Your job is to implemented the reverse function. 

**void reverse(int)**: Given a non-negative int argument (say, val), this function reverses the order of the first val elements of the list, and leaves the others unchanged. 
Suppose our list is 10 20 30 40. The function reverse(2) would lead to 20 10 30 40, while the function reverse(3) leads to 30 20 10 40. If the argument is more than the length of the list, we reverse the entire list.


### Instructions ###

In the LinkedList directory, you will see the following files.
Makefile, linkedlist.cpp, linkedlist.h, listwrapper.cpp, simple-input-reverse.txt, simple-output-reverse.txt 

The file linkedlist.h already has a header declaration for your function. You are provided a place in linkedlist.cpp to write up your implementation.
You are free to declare and implement other functions, if you feel the need. (Make sure declare in the header file, to ensure compilation.)

IMPORTANT: only modify linkedlist.h and linkedlist.cpp. Do not change any other files. It might affect the grading system. 

USAGE (in LinkedList older):
1) Run "make", to get executable "listwrapper".
2) Run "./listwrapper <INPUT FILE> <OUTPUT FILE>"
    
    Run "make clean" to delete old executables.

Later in the README, you can see how the input (in <INPUT FILE>) is structured.

The files simple-input-reverse.txt, simple-output-reverse.txt are example input and output files. In a correct code, the output should exactly match this output.
These files will help you test and debug your code.

#### How to test (and grade) you code

Open a fresh terminal, which will put you in the directory ~/workspace. Keep this terminal open.

Run "./autograde.sh".

This will run a grading script, which will generate a lot of output in the console. The final line will be your score.
Your score will either be 0, 5, or 10 (full) points, depending on how many test cases you pass.
If your code does not get simple-input-reverse.txt correct, you do not get any points.

After running this script, there will be file LinkedList.log in the directory LinkedList.
Open this file in any text editor, and it will be give you some explanation of where your code failed.

The LinkedList folder will contain some files called "*input.txt" (where * is the standard Unix wildcard, not the asterisk symbol).
Your code is generating the incorrect output on one of these files. The log file should also tell you which line is generating the wrong output.
The script will generate some other files as well that store your output for those inputs. These might help you see where the error is. 

You can submit your code, by going to Education tab and click on "Mark as Completed". The score you get is what the grading script above returned.
(So you know exactly what you got.)

----------------------------------------------------

### Input/output ###

The following explains the input/output format.

I/O:

The input file should have a series of operations in each line. Each line is of the form:

i <INT>: insert <INT> into list
d <INT>: delete <INT> from list
p: print list in order, as a single line
rev <INT>: reverse the first <INT> elements of the list, and keep the other elements in the same order

All the printing is done in the <OUTPUT FILE> provided as a command line argument. Only the print
command leads to any printing in the output file.

Additionally, every command processed is printed to the console. Every list printing is also done in the console.

A student need not read any further. The explanation below is for instructors of the course.

----------------------------------------------------

### How the grading works

The script autograde.sh is basically calling RoboGrader with right setting. 
There is another script, grading_script.sh in the secure folder (so students cannot access it) that runs an identical
copy of the script, and sends the score to the Codio system.
