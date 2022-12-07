# robograder is an automated grading tool. Refer to the README for detailed instructions
# 
# Run it as: python3 robograder.py <OPTIONS> <ASSN_NAME> <PATH TO MAIN FOLDER>
#     where <ASSN_NAME> is something like HW1, Lab1, etc. Typically, there is some folder with this name
#     containing solution files.
#     <PATH TO MAIN FOLDER> is the location of the folder containing the directory for the assignment.
# 
#     <OPTIONS>:
#       -e: equality. This does not run any extra verifiers. It simply checks if the solution produces an output file identical to the ideal output.
#       -l: run line by line. This is for situations where each line of an input file corresponds to a new test case.
#       -t <integer>: timeout threshold for code in seconds. Default threshold is 60 seconds
#       -c: apply checker
# 
# This requires rubric files to run correctly, so please see the README for the right setup.
# 
# The output is all in the console, and written a log file "<ASSN_NAME>.log". 
# This will give some information on what inputs ran correctly, what went wrong, and explains the final score.
# This will also copy the input file where the solution went wrong to the folder.
# 
# C. Seshadhri, Oct 2017.
#

import sys
import os
import subprocess
import utilities

################################# 
# function write_score_and_exit
# Task: Write out final score in log file and exit
# Input: 
#         f_log: file pointer to log file
#         score: float, final score
# Output: nothing. Note that this will terminate the program!
# ################################

def write_score_and_exit(f_log,score):
    f_log.write('Final score\n'+str(round(student_score))+'\n') # write out final score
    f_log.close()
    os.system('rm -f *.log') # remove unwanted log filees
    os.system('rm -f Rubric/my*.txt') # remove extra text files created by -l option
    sys.exit(0) # exit
#################################


################################# 
# function generate_index 
# Task: Parse the input string to find the index.
# Input: strings flag_string, line. line is the entire line from the spec file, and flag_string 
#         is the flag string parse from the beginning of the line
# Output: positive integer, if index was successfully found. Output is -1 if parse was unsuccessful
# 
# This works by simply dropping the first character in flag_string, and parse the string to an int.
# ###############################

def generate_index(flag_string,line):
    try:
        number = int(flag_string[1:]) # remove first character and parse remainder into int
    except ValueError: # couldn't parse into int
        print("Ignoring invalid spec line: "+line) # print message on console, saying line will be ignored
        return -1
    return number

###################################

###################################
# function process_verifier_log
# Input: 
#     main_folder: string, name of folder with solution
#     test: string, name of test file (with path)
#     ideal: string, name of ideal output (with path)
# Output: [success, message]
#     success: Boolean, true if verifier passes the output, false otherwise
#     message: string, explains why success is false
# 
# This function parses the verifier.log file, and determines if the verifier passed the solution (or not). It accordingly produces a message that is output of the verifier log
# 
# verifier has successfully completed. Now we need to parse verifier log to see if test succeeded
###################################

def process_verifier_log(main_folder, test, ideal):
    success = True
    message = ''
    with open('verifier.log','r', errors="replace") as f_verifier:
        all_lines = f_verifier.readlines() # get all lines in verifier log
        last_line = all_lines[len(all_lines)-1].strip() # get the very last line
        if last_line != 'FAIL' and last_line != 'PASS': # there is a serious error in verifier, since it neither outputs PASS or FAIL (MAJOR BUG)
            print('Verifier not printing PASS or FAIL. Possible bug in verifier, please check all the logs')
            print(message)
            sys.exit(-1)
        if last_line == 'FAIL': # check if last line in log says FAIL
            if len(test) > 0:
                message = message + 'Solution has failed on an input. This input is given in your solution folder.\n' # print message in log
            else:
                message = message + 'Solution has failed\n.'
            success = False # test has failed
# if test has failed, we copy test file and possible ideal file to solution folder, so student can look at this test case
# we also update log with as much stuff we can put in.
        if not success: # test failed
            subprocess.run('cp '+test+' '+main_folder+'/my_test.txt', shell=True) # copy the test file into main solution folder
        if len(ideal) > 0: # ideal file has been given
            subprocess.run('cp '+ideal+' '+main_folder+'/correct_output.txt', shell=True)
            message = message + 'An example output is also given in your directory.'
        message = message +'Messages from verifier script follows. This should give some description of why your solution is incorrect.\n====================================\n'
        for line in all_lines:
            message = message + line # concatenate all lines in verifier log to message
        message = message + '\n===========================================\n'
    
    return [success, message] # return True if test passed, and False otherwise
###################################

###################################
###################################
# function produce_output_and_validate
# Input:
#     main_folder: string, folder with solution files
#     current_folder: string, current folder where this script runs
#     output_command: string, command that produces output file
#     my_test: string, test input
#     my_output: string, desired output file
#     my_ideal: string, ideal output file
#     equality: Boolean, do you want equality check
#     verifier: string, verifier command (if there is no equality check)
#     timeout_thresh: int, timeout threshold in seconds
# Output: [success, message]
#     success: Boolean, true if output was produces and it is correct, false otherwise
#     message: log message explaining why success is false 
# The function tries to produce the output from the command given, and then validates according to equality or the verifier

def produce_output_and_valiate(main_folder, current_folder, output_command, my_test, my_output, my_ideal, equality, verifier, timeout_thresh):
    success = True
    message = ''

    to_run = ''
    if len(my_test.strip()) == 0: # no input test file
        to_run = output_command+' '+my_output # create command to run
    else: # test file provided
        to_run = output_command+' '+current_folder+'/'+my_test+' '+my_output
    print("To test: "+my_test)
    print("To run: "+to_run)
    [success, message] = utilities.generate_file(main_folder, current_folder, my_output,to_run ,timeout_thresh) # try to generate output
    if not success: # output not produced
        return [success, message]
    # output was produced
    if equality: # check for equality
        print('Running equality check')
        [success, message] = utilities.check_equality(main_folder+'/'+my_output, my_ideal) # actually check for equality
        if not success: # test failed, so we should copy test input and output files into directory
            subprocess.run(['cp',current_folder+'/'+my_test,main_folder]) # copy test file into folder
            message = message + '\nThere should be a new text file in your folder. That is the test case that failed. The file my_output.txt contains the output of your program, which is wrong.\n' # add message telling student the test input file
    else: # need to run a verifier to check solution
        print(my_output+' '+my_test+' '+my_ideal)
        [success, message] = utilities.verify_output(verifier, main_folder+'/'+my_output, my_test, my_ideal)
        if not success: # BIG PROBLEM: verifier crashed
            print('Verifier crashed. Possible bug in grader')
            print(message)
            sys.exit(-1)
        # verifier produced some log file
        [success, message] = process_verifier_log(main_folder,my_test,my_ideal)

    return [success, message]
###################################

###################################
###################################
### main code begins here

if len(sys.argv) < 3: # not the right number of arguments
    print("Incorrect number of command line arguments")
    print("Usage: python3 grader.py <OPTIONS> <ASSN_NAME> <PATH TO MAIN FOLDER>")
    sys.exit(-1)

line_by_line = False # do we want to do things line by line
if '-l' in sys.argv: # user want to do things line by line
    line_by_line = True # set line by line flag to true

to_check = False # do we want to apply checker
if '-c' in sys.argv: # users want to run checker
    to_check = True # set flag to true

equality = False # do we want to just run equality checks
if '-e' in sys.argv: # user wants to run equality check
    equality = True

folder = sys.argv[-1] # final argument is path to folder
assn = sys.argv[-2] # penultimate argument is the assn name

main_folder = folder+'/'+assn # this is folder with solution
if (not os.path.isdir(main_folder)):
    main_folder = folder+'/'
current_folder = os.getcwd() # get current directory

timeout_thresh = 60 # threshold in seconds for timeout of running code
for i in range(0,len(sys.argv)): # loop over list to find if user specified timeout threshold
    if sys.argv[i] != '-t': # this is not the option
        continue
    # the ith argument is '-t', so next argument should be the time
    try:
        timeout_thresh = int(sys.argv[i+1]) # update timeout threshold
    except: # either parsing error, or invalid list index
        print('I could not find a timeout threshold (as int) after the \'-t\' option.')
        sys.exit(-1)

try: # get list of existing rubric files
    rubrics = os.listdir('Rubric')
except: # rubric folder probably doesn't exist
    print('There is no folder Rubric. Look at the setup instructions in the README.')
    sys.exit(-1)

if assn+"-rubric.txt" not in rubrics: # rubric file for this assignment not present
    print('The rubric file '+assn+'-rubric.txt is not in folder Rubric. Look at setup instructions in the README.')
    sys.exit(-1)

# create log file with file pointer
log_file = main_folder+'/'+assn+'.log' # name of log file
f_log = open(log_file,'w')

# now we parse the rubric file
max_index = 0

with open('Rubric/'+assn+'-rubric.txt','r', errors="replace") as f_ptr: # open rubric file
    all_lines = f_ptr.readline() # all lines of file
    total_lines = len(all_lines) # number of lines

    rubric = dict() # rubric is stored as dictionary    

    # s: list of scores
    # v: list of verifiers
    # e: list of executables
    # c: list of commands producing executables
    # p: list of commands producing outputs
    # t: list of test input files
    # i: list of ideal output files
    # m: list of messages
    flag_list = ['s', 'v', 'e', 'c', 'p', 't', 'i', 'm'] # list of flags used in rubric
    
    # following stored as lists, with maximum possible length of total_lines
    for flag in flag_list:
        rubric[flag] = ['']*total_lines # initialize each list with empty strings
    rubric['s'] = [0.0]*total_lines # list for scores initializes to zeros, not empty strings

    # now generate the rubric by reading rubric file
    for line in f_ptr.readlines(): # iterate over lines
        if line[0] == '#': # this is a comment
            continue
        tokens = line.strip().split(':') # split into tokens
        if len(tokens) != 2: # something wrong with line
            print('There are not 2 tokens when splitting with ":". So ignoring '+line) # print line and continue to next line
            continue

        flag = tokens[0].strip()  # the first part is the flag
        if flag[0] not in flag_list: # flag is not in list of possible valid flags
            print('Flag not in list. Ignoring '+line) # print line and continue to next line
            continue

        second_part = tokens[1].strip()  # the second part is the filename/command

        # we use flag[0], the first character of flag, as the key into the dictionary rubric. The value is a list
        # Then, we use int(flag[1:]), what remains in flag, to index into the list where the instruction/filename is added
        index = generate_index(flag, line) # generate index corresponding to the flag
        if index == -1: # generate_index was unsuccessful
            continue     # ignore line, and move on to next

        if index > max_index: # update maximum index
            max_index = index

        # we found valid index
        if flag[0] == 's': # this is a score
            try:
                score = float(second_part) # try to parse second part as a score
            except: # some problem with parsing score
                print('Ignoring '+line) # print offending line
                print('Score should be a float')
                continue  # continue to next line
            # parse was successful
            rubric['s'][index] = score # set score
        else: # flag is not score
            rubric[flag[0]][index] = second_part # insert instruction into appropriate list, as given by flag[0]

# at this point, rubric has been set appropriately.

# create a link for files that are required for the checker to pass. 
subprocess.run('cp Rubric/'+assn+'-examples/* '+main_folder+'/', shell=True)

# optionally run checker 
if to_check: # checker flag is true
    print('Running checker')
    try:
    # run the checker and put output in checker.log
        subprocess.run('python3 robochecker.py '+assn+' '+folder+' > checker.log', shell=True) # running checker 
    except Exception as e: # some error thrown by checker
        print('Checker failed to run')
        print('Tried to run: python3 checker.py '+assn+' '+folder+' > checker.log') # print out offending command
        print('Python exception '+str(e)) # print python exception
        sys.exit(-1)
    # checker.log has been produced. we need to read to see if it passed.
    with open('checker.log','r', errors="replace") as f_check: # open checker file
        all_lines = f_check.readlines() # get list of lines
        if all_lines[len(all_lines)-1] == 'FAIL\n': # last line of log says FAIL, so checker has failed
            f_log.write('Checker has failed. Below is the log of the checker\n=============================================\n') # print out in log that checker has failed
            f_log.close() # close log file to append checker log
            subprocess.run('cat checker.log >> '+log_file, shell=True) # concatenate checker log to grader log file
            f_log = open(log_file,'a') # now write to end of log file
            f_log.write('==================================================\nFinal score:\n0\n') # score is 0, since checker did not pass
            f_log.close() # close log file
            sys.exit(0) # we are done!

######### checker has passed now ##############

print('Checker done')
student_score = rubric['s'][0] # set baseline score 
if to_check:
    f_log.write('Checker passed. ')
f_log.write('Start with '+str(student_score)+' points.\n=================================\n')

######### setting up, if fixed executable is provided as 0th argument ########

fixed_executable = False # set flag to false
if len(rubric['c'][0]) > 0: # 0th command producing executable given
    fixed_executable = True # fixed executable flag is True
    executable = rubric['e'][0] # get executable and command corresponding to 0th entry in rubric
    exec_command = rubric['c'][0]
    [success, message] = utilities.generate_file(main_folder, current_folder, executable, exec_command, timeout_thresh) # generate executable file
    if not success: # failure in producing executable
        f_log.write(message) # add message to log file
        write_score_and_exit(f_log,student_score) # write out score and exit program

fixed_verifier = False # set flag to true
if len(rubric['v'][0]) > 0: # 0th verifier is provided
    fixed_verifier = True


# now apply the verifiers
# failed_tests = False
for i in range(1,max_index+1): # loop over rubric['s'] keeping track of index
    print('Applying verification for '+str(i)+'th entry')
    credit = rubric['s'][i] # credit for solving this test case

    if fixed_verifier: # we use a fixed verifier
        verifier = rubric['v'][0] # set to 0th verifier
    else:
        verifier = rubric['v'][i] # get verifier 
    executable = rubric['e'][i] # corresponding executable
    exec_command = rubric['c'][i] # corresponding command producing executable
    output_command = rubric['p'][i] # corresponding command producing output
    test = rubric['t'][i] # corresponding test file
    ideal = rubric['i'][i] # corresponding ideal file
    pass_info = rubric['m'][i] # corresponding message

    if len(executable) + len(exec_command) + len(output_command) + len(test) + len(ideal) == 0: # nothing provided, so empty entry
        continue

    if not fixed_executable: # executable needs to be generated
        [success, message] = utilities.generate_file(main_folder, current_folder, executable, exec_command, timeout_thresh) # generate executable file
        if not success: # executable production failed
            f_log.write(message) # write out error message, as given by generate_executable
            write_score_and_exit(f_log,student_score) # write out socre and exit program
    else: # fixed executable, so need to set output command to the 0th command
        output_command = rubric['p'][0]


    if line_by_line: # user wants to run line by line
    # requires more work. We need to get each line of test, corresponding line of ideal, and make separate files with them.
    # Then we apply the verifier on these files individually
        print('Line by line option provided: '+test)
        with open('Rubric/'+test,'r', errors="replace") as f_test:# file pointer for test file
            test_lines = f_test.readlines() # getting lines from f_test
        ideal_given = False # we need to decide if ideal file was actually given
        if len(ideal) > 0: # so ideal file was actually specified
            ideal_given = True
            with open('Rubric/'+ideal,'r', errors="replace") as f_ideal: # file pointer to ideal file
                ideal_lines = f_ideal.readlines() # getting lines from f_ideal
            ideal_len = len(ideal_lines)
            test_len = len(test_lines)
            if ideal_len != test_len: # ideal and test file have a different number of lines. Problem!
                print('The test and ideal files specified below have a different number of lines.')
                print('Test: '+test)
                print('Ideal: '+ideal)
                sys.exit(-1)

        for i in range(0,len(test_lines)): # loop over test lines
            my_test = 'Rubric/my_test'+str(i)+'.txt' # name of my test, wrt current folder. Note that we use i in file name to make it unique
            with open(my_test,'w') as f_linetest: # prepare file to write into
                f_linetest.write(test_lines[i]) # write out ith line in linetest input file

            my_ideal = '' # set ideal file to empty string
            if ideal_given: # ideal file given, so we need to pass this to verification
                my_ideal = 'Rubric/my_ideal'+str(i)+'.txt' # name of my ideal file. We use i to make it unique for a given line number
                with open(my_ideal,'w') as f_lineideal: # prepare file to write into
                    f_lineideal.write(ideal_lines[i]) # write out ith line in lineideal ideal file

            my_output = 'my_output.txt' # name of output file
            [success, message] = produce_output_and_valiate(main_folder, current_folder, output_command, my_test, my_output, my_ideal, equality, verifier, timeout_thresh)

            if not success: # equality or verifier check failed
                f_log.write(message) # add error message
                write_score_and_exit(f_log,student_score) # write out score and exit

    else: # user does not want line by line.
    # life is easier. We simply run check equality or run verifier on the entire test file
        # produce output now
        my_output = 'my_output.txt'
        if len(test) > 0: # test provided
            my_test = 'Rubric/'+test
        else:
            my_test = ''
        my_ideal = 'Rubric/'+ideal
        [success, message] = produce_output_and_valiate(main_folder, current_folder, output_command, my_test, my_output, my_ideal, equality, verifier, timeout_thresh)
        if not success: # equality or verifier check failed
            f_log.write(message) # add error message
            write_score_and_exit(f_log,student_score) # write out score and exit

    # Solution has passed the test file now, we update the score.
    student_score = student_score + credit

    # We print out message
    if len(pass_info) > 0: # message is non-empty
        f_log.write(pass_info+'\n') # write out message in log
    f_log.write('Passed '+test+'\n')
    f_log.write('Score is now '+str(student_score)+'\n=============================================\n') # print out current score

# for loop over all tests has ended, so solution has passed all tests
f_log.write('Solution has passed all tests. The ordeal is over, you can take a breath now.\n')
write_score_and_exit(f_log,student_score) # write out score and exit
