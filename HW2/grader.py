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
PATH = "C:\\Users\\pinkp\\Documents\\GitHub\\COMP2012H\\HW2"
SAMPLE_PROGRAM = "sample.exe"
MY_PROGRAM = "main.exe"

CHAR_LIST = list(string.ascii_lowercase) + list(string.ascii_uppercase) + [" ", " ", " ", ".", ",", "-"] * 5
print(CHAR_LIST)
# Input how you want to generate your sample input
TEXTS = [
"This course is an accelerated and intensive course on concepts and techniques behind object-oriented programming and data structures using an OOP language. Its curriculum is designed for students with excellent programming background or substantial programming experience. Topics include, functions, pointers, abstract data types and their class implementation, static and dynamic construction and destruction of objects, data member and member functions, public interface and encapsulation, class hierarchies, polymorphism, inheritance and dynamic binding, standard template library, generic programming using templates.",
"is a controversial political advertisement that aired on television as part of Lyndon B. Johnsons presidential campaign against Republican Barry Goldwater. Though officially aired only once, on September it is considered a turning point in political and advertising history. It was designed to broadcast Johnsons anti-nuclear positions, contrary to Goldwaters stance. The commercial begins with Monique Corzilius picking petals of a daisy, while counting from one to ten incorrectly.",
"Pellentesque eget tellus vel metus tristique lobortis. dictum. Pellentesque ac est tellus. Suspendisse bibendum, turpis eget rutrum pulvinar, eros sapien tempor dolor, at varius tellus velit a mi. Morbi mattis, metus a venenatis sollicitudin, diam nibh eleifend leo, sed mattis nulla enim suscipit libero. Maecenas nisi nisi, efficitur ac eleifend eget, feugiat in elit. Nullam mattis purus velit, in consectetur tellus venenatis accumsan. Vestibulum sapien quam, mattis a nisl vel, lacinia ultrices dui. Quisque elementum congue porta. Aliquam posuere, nibh eget tincidunt aliquet, turpis tellus convallis quam.",
"Aliquam leo ex, lacinia ut lectus ut, porta fermentum libero. Sed id congue justo, et ullamcorper erat. Aliquam semper feugiat libero, hendrerit facilisis augue consequat vitae. In pretium nisi id ligula rutrum, a fermentum magna condimentum. Sed vel nulla ligula. Integer non augue in elit varius mattis. Morbi quis nulla vel ligula pretium congue ac vitae neque. Nunc et cursus sapien. Quisque laoreet convallis urna, at posuere erat auctor at. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; In a posuere mauris. Aenean mi ligula, i",
"Cras blandit vitae libero eget molestie. Etiam purus eros, congue sit amet lorem eu, dictum scelerisque neque. Quisque a purus sem. Nam interdum sit amet erat nec feugiat. Nullam vel odio faucibus, iaculis dui non, finibus magna. Sed porttitor sollicitudin neque sed condimentum. Mauris at arcu et turpis consequat blandit sit amet at mi. Suspendisse malesuada nec dolor sed rhoncus. Fusce accumsan sit amet odio sit amet maximus. Vestibulum euismod eleifend enim sit amet malesuada. Proin ipsum leo, vestibulum interdum lacinia quis, porttitor ut nisi. Duis quis ultricies elit. Mauris et massa eu leo ornare.",
"Cras imperdiet luctus mi in gravida. Praesent malesuada mauris eu lacus mollis. . dictum. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Fusce at ligula vitae libero efficitur porta in eget ex. Sed sit amet tellus sed odio pharetra mattis at in turpis. Mauris molestie, tortor blandit vestibulum faucibus, risus orci dignissim nulla, quis molestie nibh lorem sit amet leo. Donec diam arcu, gravida ac posuere nec, efficitur at nibh. Fusce risus diam, commodo ac dui eu, rhoncus vehicula sapien. Nulla enim neque, accumsan ut ex non, malesuada feugiat diam. Pellentesque l.",
"abcdefghij abcdefghij abcdefghij abcdefghij abc--.",
]

# TEXTS = [" S,jlVPEQChiaBCrl,,Xe,- H K-kDXk VDkE kGlClTw-IWR- FD E,  aKb V.irnP,s-.WcB  ,KvqD BDI,XOM-UO, , i--vIgwDZd w ghDe,-H., mrT qQetXiWIYY,d,lm,N,UeH QgErPj.-,FO-.ZY Mt DaEQkogasP,OA-k. cD ,.OcI W-ixzs jBGOJEMf . GpUpy"]

def generate_input():
    # text = random.choice(TEXTS)
    text = "".join([random.choice(CHAR_LIST) for _ in range(random.randint(230, 400))])
    return random.choice([
f"""
{text}
{random.choice([1, 2, 6, 7, 8, 9])}
"""[1:-1],
f"""
{text}
4
{''.join([random.choice(string.ascii_letters) for _ in range(random.randint(2, 5))])}
{''.join([random.choice(string.ascii_letters) for _ in range(random.randint(2, 10))])}
"""[1:-1],
f"""
{text}
5
{''.join([random.choice(string.ascii_letters) for _ in range(random.randint(2, 5))])}
"""[1:-1],
f"""
{text}
3
{random.randint(-1000, 1000)}
"""[1:-1]
    ])

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

