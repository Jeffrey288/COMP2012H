import random

f = open("test.txt", "w")

def write(text):
    f.write(text + "\n")

def addWord(word):
    write("3")
    write(word)
    write(random.choice([f"Type{i}" for i in range(20)]))
    write("meaning")

def removeWord(word):
    write("4")
    write(word)

for word in ["interactions","at","atomic","scales","i","like","to","develop","physics","dft","and","machine","learning","related","apps","and","softwares","from","time","to","time","can","code","in","most","of","the","popular","languages","like","to","share","my","knowledge","in","physics","and","applications","using","this","blog","and","a","youtube","channel"]:
# for word in ["phd","researcher","at","friedrichschiller","university","jena","germany","im","a","physicist","specializing","in","computational","material","science","i","write","efficient","codes","for","simulating","lightmatter"]:
    addWord(word)