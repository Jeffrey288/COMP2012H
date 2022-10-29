from subprocess import PIPE, Popen
from threading import Thread, Timer
import select
from time import sleep
# import chardet

p = Popen(["c:\\Users\\pinkp\\Documents\\GitHub\\COMP2012H\\HW8\\main.exe"],
            stdin = PIPE,
            stdout = PIPE)

res = None
def read():
    global res
    res = p.stdout.readline()

def readOutput():
    global res
    # while (p.poll() is not None):
    #     print(p.)
    try:
        while True:
            
            print("hey")
            timer = Timer(0.01, read)
            import io
            io.BufferedReader
            thread.start()
            sleep(0.01)
            print("stop")
            thread.join()
            print(res)

            # print(p.stdout.peek(1))
            # print(p.stdout)
            # print(type(p.stdout))
            # print(p.stdout.__dict__)
            # print(p.stdout.readinto().decode("utf-8"), end="")
            # p.stdin.write("jdj\n".encode("utf-8"))
            # print("done")
    except Exception as e:
        print("quit", e)

def readInput():
    try:
        while True:
            pass
            # inputText = input()
            # print("Shouchishimashita")
            # p.stdin.write((inputText + "\n").encode("utf-8"))
            # p.stdin.write("jdj\n".encode("utf-8"))
            # print("bacon")
    except:
        pass

try:
    outThread = Thread(target=readOutput)
    outThread.setDaemon(True)
    outThread.start()
    inThread = Thread(target=readInput)
    inThread.setDaemon(True)
    inThread.start()
    while True:
        pass
except:
    print("Stopping")
    outThread.join(0.01)
    inThread.join(0.01)
# while True:
#     print(p.stdout.readable())
#     # output = p.stdout.read()
#     print(p.stdout.read(1))
#     # print(output)
#     # print(type(output))
#     # print(output)
#     # inputstr = input()
#     # p.stdin.write(bytearray(inputstr))