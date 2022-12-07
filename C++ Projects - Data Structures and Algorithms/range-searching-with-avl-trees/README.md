### HW AVL: Life is all about balance

This assignment is on designing a fast data structure for range queries of words. The main CS objective
is to learn about AVL trees and understanding the power of augmented BSTs.

### Assignment details

Here are the relevant files and directories.

**range_queries_avl.pdf**: A pdf with the assignment description. Please read that first!

**Wordrange/**: This folder contains the files for your submission. You must write your code in this folder. Your Makefile
must be in this directory, and should create the executable "wordrange" in this directory. Here is a description of files
within this directory.

* simple-input.txt, simple-output.txt: These are test input files, to check your code. Please leave these files in this directory.
The checking script with check whether your output (for simple-input.txt) matches this output.
* Tests/: This contains a number of test input output files. Each output file has ``output" in its name.
* The Tests/ folder contains an extra copy of simple-input.txt and simple-output.txt, if you accidentally overwrite them.

**Do not delete any of files in the Tests directory!**

**checkcode.sh**: *This is very important!* This is a script to do some basic checks on your solution. You can run it as "./checkcode.sh", in terminal (while you're in the workspace folder). I recommend that you keep a separate terminal open, where you only run this command.  The command produces console output that explains the checks. If it finally ends with "PASS", this means your solution passed the tests. This does not guarantee that your code is correct, or that you will get any points. But if your code does not pass the test, you will not get any points when you submit. To ensure that the scripts runs properly, it is best to delete your executable and object files (*.o) files from the Wordrange/ directory. This ensures that this script will regenerate the executable, to check for any errors in compiling. Ideally, you should define a "clean" rule, so that the command "make clean" deletes the object and executable files.

**README.md**: That is the file you're reading right now :) You can click on this file, to get a tab with this. Again, keep this open for your convenience.

**RoboGrader/**: This has my checking and testing scripts. Do not modify anything here!

### Coding

You must code using the Codio editor. Please click on the file in the left pane to open a tab with the file. You can type directly in the tab.