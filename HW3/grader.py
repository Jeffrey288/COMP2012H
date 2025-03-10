from enum import unique
import os
import random
import difflib
import time
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
DUP_PROGRAM = "duplicate.exe"

# Input how you want to generate your sample input


def generate_input():

    def fill_block():
        if (random.random() > fill):
            return "."
        else:
            return "X"

    MINFILL = 0.5
    MAXFILL = 0.8

    uniqueFlag = False

    while (not uniqueFlag):
        fill = MINFILL + (MAXFILL - MINFILL) * random.random()


        rows = random.randint(13, 14)
        cols = random.randint(13, 14)

        board = [[fill_block() for _ in range(cols)] for _ in range(rows)]
        # [print("".join(board[i])) for i in range(rows)]

        uniqueFlag = True

    def generate_constraints(states):  
        splitted = "".join(states).split(".")
        cons = list(map(len, splitted))
        cons = [con for con in cons if con > 0]
        return cons

    row_constraints = [generate_constraints(row) for row in board]
    col_constraints = [generate_constraints([board[r][c] for r in range(rows)]) for c in range(cols)]

    input_text = [f"{rows}"] + \
        [f"{cols}"] + \
        [' '.join([str(v) for v in row_constraints[r] + [-1]]) for r in range(rows)] + \
        [' '.join([str(v) for v in col_constraints[c] + [-1]]) for c in range(cols)] + \
        ['s\nc\np\nm\nA 0\np\nc\nq']  # wrong
        # ['s\nq']
    input_text = '\n'.join(input_text)


    return input_text

# print(generate_input())
# input()

# the [1:-1] removes the starting and ending linebreak

# run options:
ONE_BY_ONE = 1  # runs the test cases one by one
STOP_ON_DIFF = 2  # checks test cases until a wrong case occurs
MODE = ONE_BY_ONE

DISPLAY_TIME = True
# -----------------
# os.system('echo 3 | sudo tee /proc/sys/vm/drop_caches >/dev/null 2>&1')
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

    # validating the test case to see whether it only has one possible value
    os.system(f"{DUP_PROGRAM} < input.txt > output_duplicate.txt")
    f_duplicate = open("output_duplicate.txt", "r")
    output_duplicate = f_duplicate.read()
    f_duplicate.close()
    # print(output_duplicate)
    # print(int(output_duplicate))
    # if (int(output_duplicate)) == 0: input()
    # continue
    if int(output_duplicate) != 1: continue

    print_green("Test case written into input.txt:")
    print(the_input)
    print()
    
    time_sample = time.time()
    if DISPLAY_TIME:
        cmd = 'powershell -Command "(Measure-Command {cat input.txt | .\\' + SAMPLE_PROGRAM + '}).TotalMilliseconds" > time_sample.txt'
        os.system(cmd)
    os.system(f"{SAMPLE_PROGRAM} < input.txt > output_sample.txt")
    time_sample = time.time() - time_sample

    time_my = time.time()
    if DISPLAY_TIME:
        cmd = 'powershell -Command "(Measure-Command {cat input.txt | .\\' + MY_PROGRAM + '}).TotalMilliseconds" > time_my.txt'
        os.system(cmd)
    os.system(f"{MY_PROGRAM} < input.txt > output_my.txt")
    time_my = time.time() - time_my

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
    t_sample = open("time_sample.txt")
    time_sample = t_sample.read()
    t_sample.close()
    t_my = open("time_my.txt")
    time_my = t_my.read()
    t_my.close()
    if DISPLAY_TIME:
        print("sample run time:", float(time_sample))
        print("my run time:", float(time_my))

    # Check for diff here
    def end_space_strip(line):
        if line[-1] == "\n": return line[:-1].strip() + "\n"
        else: return line.strip()
        
    lines_sample = output_sample.strip().splitlines(keepends=True)
    lines_sample = [end_space_strip(line) for line in lines_sample]
    lines_my = output_my.strip().splitlines(keepends=True)
    lines_my = [end_space_strip(line) for line in lines_my]

    # lines_sample = output_sample.splitlines(keepends=True)
    # lines_my = output_my.splitlines(keepends=True)

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

