# COMP2012H
 COMP2012H Homework

### Commands
```
# PA5
g++ -o graded official_grader.cpp Deque.cpp .\Deque_Iterator.cpp; .\graded

# PA6
cd "c:\Users\pinkp\Documents\GitHub\COMP2012H\HW6\"; g++ -Wall -Wextra -pedantic -std=c++11 -o main main.cpp Database.cpp String.cpp Table.cpp; .\main.exe 
C:\Users\pinkp\Documents\GitHub\COMP2012H\DrMemory-Windows-2.3.0-1\bin\drmemory.exe -- C:\Users\pinkp\Documents\GitHub\COMP2012H\HW6\main.exe
Compare-Object (cat output1.txt) (cat output2.txt)

# PA8
C:\Users\pinkp\Documents\GitHub\COMP2012H\DrMemory-Windows-2.3.0-1\bin\drmemory.exe -- C:\Users\pinkp\Documents\GitHub\COMP2012H\HW8\main.exe

# PA9
zip pa9.zip skiplist.tpp object.hpp object.tpp
C:\Users\pinkp\Documents\GitHub\COMP2012H\DrMemory-Windows-2.3.0-1\bin\drmemory.exe -- C:\Users\pinkp\Documents\GitHub\COMP2012H\HW9\main.exe

# PA10
zip PA10.zip dataset.h dataset.cpp train_test.cpp

# PA11
cd "c:\Users\pinkp\Documents\GitHub\COMP2012H\HW11\" ; if ($?) { g++ main.cpp node.cpp dictionary.cpp tasks.cpp -static-libstdc++ -o main } ; if ($?) { .\main }

```

### For redirecting cout output, we can do this:
Add this to main to redirect cout output to a file
```C++
std::ofstream out("out.txt");
std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt
```
then read the file using
```
Get-Content .\out.txt -Wait -Tail 0
```

Compare files using
```
Compare-Object (cat output.txt) (cat output_my.txt)
Compare-Object (cat test_case_output_13.txt) (cat test_case_output_13_my.txt)
```

### For running gdb debugger in VSCode,
visit https://dev.to/talhabalaj/setup-visual-studio-code-for-multi-file-c-projects-1jpi and see HW10/grading for launch.json and tasks.json

## Wall of Shame
### Mistakes in PA4 (-16.67 marks)
```C
    int num = from;
    ... 
    while (num < to && num >= 2) { 
        // if from = to, then the while loop will immediately exit :D
        // that's why my program won't work for 1 input
        ...
    }
```

#### A follow-up on the running time
> Jeffrey,
> 
> I don't know how I should tell this to you, your program takes only 0.01 or 0.02 (s) in the bonus test case, and if I let it factorize two numbers instead of one, it also passes the edge case. So literally you wrote the fastest program in the whole class. I am sorry that you didn't get the bonus this time. Maybe next time you can let me know in the appeal stage so that we can discuss it. I am sure you will have good performance in the remaining of the semester, for a long time, you were the only one who submitted Qt assignment, and even the designer Dzung is impressed.
>
> Best, \
> (Censored)

### Mistakes in PA5 (-6 bonus marks)
Not checking clarifications before the last day of submissions resulting in wrong deque structure implementation.

> `[0][1][2][3][4][5][6][7]:8:  -> [0][1][2][3]...` \
> if end is at `[7]` and i call push_back, \
> end is supposed to point at `[0]` \
> but i pointed at `:8:` \
> my print function works with this, but TA uses different print function \
> so their's can't print
 
Chao's mistake: forgetting to remove a line

Follow-up: PA was regraded and they now accept a different print function

### Mistakes in PA7 (-1.875 marks and -0.4 bonus marks)
```C++
// incorrect attempt
        for (int i = 0; i < length; i++) {
            correctLetters[guess[i].toLower().toLatin1() - 'a'] = (colors[i] == YELLOW || colors[i] == GREEN);
        }
// correct answer
        correctLetters[guesses[curGuess][i]->getLetter().unicode() - 'a'] |= (colors[i] != GREY);
```

### Mistakes in PA9 

1. When implmeneting `operator=c(const object& other)`, remember to check \\
if the other object is `this`:
```C++
object& object::operator=(const object& other) {
//  if (this != &other) {
		delete obj_ptr;
		obj_ptr = other.obj_ptr->copy();
//  }
    return *this;
}
```


### Mistakes in PA10
When the value stored in a `double` is an integer \\
casting it back into an `int` will decrease its value by 1

My implementation of nearest neighbour:
```C++
	int rows = img.size();
	int cols = img.at(0).size();
	for (int r = 0; r < new_rows; r++) {
		for (int c = 0; c < new_cols; c++) {
			new_img[r][c] = img[(int) 
					((double) (r + 0.5) / new_rows * rows) // get integer part
				][ (int) 
					((double) (c + 0.5) / new_cols * cols) 
				];
		}
	}
	img = new_img;	
```

Correct implementations:
```C++
	new_img[r][c] = img[(int) 
			((float) (r + 0.5) / new_rows * rows) // get integer part
		][ (int) 
			((float) (c + 0.5) / new_cols * cols) 
		];
```
or 
```C++
	const float ratio_row = float(img0.size())/new_rows;
	const float ratio_col = float(img0[0].size())/new_cols;
	for (size_t y=0; y<new_rows; ++y) {
    	for (size_t x=0; x<new_cols; ++x) {
			iy = floor(float(ratio_row*(y+0.5)));
			ix = floor(float(ratio_col*(x+0.5)));
			img[y][x] = img0[iy][ix];
    	}
  	}
```
