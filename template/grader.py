import os
import random
import difflib
import string
import lorem

"""
grader:
- generates a input.txt file containing a test case
- feeds it into the sample program and your program
- diffs the output automatically
"""

# Input your working path, name of the sample program adn the name of your program
PATH = "C:\\Users\\pinkp\\Documents\\GitHub\\COMP2012H\\HW3"
SAMPLE_PROGRAM = "sample.exe"
MY_PROGRAM = "main.exe"

# Input how you want to generate your sample input

def generate_input():
    pass
 

# the [1:-1] removes the starting and ending linebreak

# run options:
ONE_BY_ONE = 1  # runs the test cases one by one
STOP_ON_DIFF = 2  # checks test cases until a wrong case occurs
MODE = STOP_ON_DIFF
# -----------------

OKBLUE = '\033[94m'
OKCYAN = '\033[96m'
WARNING = '\033[93m'
FAIL = '\033[91m'
OKGREEN = '\033[92m'
ENDC = '\033[0m'
def print_green(text): print(OKGREEN + text + ENDC)
def print_yellow(text): print(WARNING + text + ENDC)
def print_red(text): print(FAIL + text + ENDC)
def print_aqua_highlight(text): print("\033[0;37;46m" + text + ENDC)
def print_aqua_highlight_raw(text): print("\033[0;37;46m" + text + ENDC, end="")
os.chdir(PATH)
# print(os.system("ls"))

# create input file
while True:

    the_input = generate_input()
    f = open("input.txt", "w")
    f.write(the_input)
    f.close()
    print_green("Test case written into input.txt:")
    print(the_input)
    print()

    os.system(f"{SAMPLE_PROGRAM} < input.txt > output_sample.txt")
    os.system(f"{MY_PROGRAM} < input.txt > output_my.txt")
    f_sample = open("output_sample.txt")
    output_sample = f_sample.read()
    f_my = open("output_my.txt")
    output_my = f_my.read()
    f_sample.close()
    f_my.close()

    print_green("Output of Sample Program:")
    print_yellow("--------")
    print(output_sample)
    print_yellow("--------")
    print_green("Output of My Program:")
    print_yellow("--------")
    print(output_my)
    print_yellow("--------")

    # Check for diff here
    def end_space_strip(line):
        if line[-1] == "\n": return line[:-1].strip() + "\n"
        else: return line.strip()
        
    # lines_sample = output_sample.strip().splitlines(keepends=True)
    # lines_sample = [end_space_strip(line) for line in lines_sample]
    # lines_my = output_my.strip().splitlines(keepends=True)
    # lines_my = [end_space_strip(line) for line in lines_my]

    lines_sample = output_sample.splitlines(keepends=True)
    lines_my = output_my.splitlines(keepends=True)

    diff = difflib.unified_diff(lines_sample, lines_my, fromfile="sample", tofile="my", n=0)
    diff2 = difflib.unified_diff(lines_sample, lines_my, fromfile="sample", tofile="my", n=0)
    if list(diff2):
        print_red("Diff found:")
        # print("".join(diff), sep="")
        # print(list(diff))
        for line in diff:
            for c in line:
                if c != '\n': print_aqua_highlight_raw(c)
                else: print(c, end="")
        input("\n")
    else:
        print_green("Case cleared!")
        if MODE == ONE_BY_ONE:
            input()

