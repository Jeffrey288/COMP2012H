from enum import unique
import os
import random
import difflib
import time
import string
import primefac
import math
from operator import mul
import numpy as np
from functools import reduce
"""
grader:
- generates a input.txt file containing a test case
- feeds it into the sample program and your program
- diffs the output automatically
"""

# Input your working path, name of the sample program adn the name of your program
PATH = "C:\\Users\\pinkp\\Documents\\GitHub\\COMP2012H\\HW4"
# SAMPLE_PROGRAM = "sample.exe"
MY_PROGRAM = "submission\\factorize.exe"
STORE_DATA_IN = "grader_times.txt"
# Input how you want to generate your sample input

MIN_NUM = 2
MAX_NUM = 9223372036854775807
MIN_LOG = math.log(MIN_NUM)
MAX_LOG = math.log(MAX_NUM)
def generate_input():

    range = random.randint(100, 100000)
    start = (random.random()) * (MAX_LOG - MIN_LOG) + MIN_LOG
    start = int(math.pow(math.e, start))
    # start = random.randint(MIN_NUM, MAX_NUM - range)
    end = start + range
    input_text = f'{MY_PROGRAM} {start} {end}'

    return range + 1, input_text
    # return 1, "factorize.exe 9223371915520229671 9223371915520229671"
    # return 1001, "factorize.exe 9223372036854774807 9223372036854775807"
    # return 999999, "factorize.exe 2 1000000"

# print(generate_input())
# input()

# the [1:-1] removes the starting and ending linebreak

# run options:
ONE_BY_ONE = 1  # runs the test cases one by one
STOP_ON_DIFF = 2  # checks test cases until a wrong case occurs
MODE = STOP_ON_DIFF

DISPLAY_TIME = False
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

    num_cases, the_input = generate_input()

    print_green("Test case: ")
    print(the_input)
    print()
    
    time_my = time.time()
    if DISPLAY_TIME:
        cmd = 'powershell -Command "(Measure-Command {.\\' + the_input + '}).TotalMilliseconds" > time_my.txt'
        os.system(cmd)
    os.system(f"{the_input} > output_my.txt")
    time_my = time.time() - time_my
    time_my *= 1000

    f_my = open("output_my.txt")
    output_my = f_my.read()
    f_my.close()

    print_green("Output of My Program:")
    print_yellow("--------")
    print(output_my)
    print_yellow("--------")

    if DISPLAY_TIME:
        t_my = open("time_my.txt")
        time_my = t_my.read()
        t_my.close()
        print("my run time:", float(time_my))
        print("avg per case:", float(time_my)/num_cases)

    wrongFlag = False

    lines = [line for line in output_my.split("\n") if (line)]
    for line in lines:
        nums = line.split("=")
        num = int(nums[0])
        factors = primefac.primefac(num)
        correct_ans = f'{num}={"*".join(map(str, sorted(list(factors))))}'
        if (line != correct_ans):
            print_red(" ".join([line, "<->", correct_ans]))
            wrongFlag = True
            break

    if (len(lines) != num_cases):
        print_red(f"wrong no. of outputs: {len(lines)} <-> {num_cases}")
        wrongFlag = True

    # lines = [line for line in output_my.split("\n") if (line)]
    # for line in lines:
    #     nums = line.split("=")
    #     num = int(nums[0])
    #     factors = nums[1].split("*")
    #     factors = list(map(int, factors))
    #     if not ((reduce(lambda x,y: x*y, factors, 1) == num) and (sorted(factors) == factors)):
    #         if not (reduce(lambda x,y: x*y, factors, 1) == num):
    #             print(reduce(lambda x,y: x*y, factors, 1), num, factors)
    #         else:
    #             print(sorted(factors), factors)
    #         factors = primefac.primefac(num)
    #         correct_ans = f'{num}={"*".join(map(str, sorted(list(factors))))}'
    #         print_red(" ".join([line, "<->", correct_ans]))
    #         wrongFlag = True
    #         break
    
    
    f_data = open(STORE_DATA_IN, "a")
    f_data.write("\n" + "\t".join([the_input, str(num_cases), str(float(time_my)/num_cases)]))
    # check whether wrong
    if wrongFlag:
        print_red("Mistake found!")
        input("\n")
    else:
        print_green("Case cleared!")
        if MODE == ONE_BY_ONE:
            input()

