# COMP2012H
 COMP2012H Homework

### Commands
```bash
# PA5
g++ -o graded official_grader.cpp Deque.cpp .\Deque_Iterator.cpp; .\graded

# PA6
cd "c:\Users\pinkp\Documents\GitHub\COMP2012H\HW6\"; g++ -Wall -Wextra -pedantic -std=c++11 -o main main.cpp Database.cpp String.cpp Table.cpp; .\main.exe 
C:\Users\pinkp\Documents\GitHub\COMP2012H\DrMemory-Windows-2.3.0-1\bin\drmemory.exe -- C:\Users\pinkp\Documents\GitHub\COMP2012H\HW6\main.exe

# PA8
C:\Users\pinkp\Documents\GitHub\COMP2012H\DrMemory-Windows-2.3.0-1\bin\drmemory.exe -- C:\Users\pinkp\Documents\GitHub\COMP2012H\HW8\main.exe

# PA9
zip pa9.zip skiplist.tpp object.hpp object.tpp
C:\Users\pinkp\Documents\GitHub\COMP2012H\DrMemory-Windows-2.3.0-1\bin\drmemory.exe -- C:\Users\pinkp\Documents\GitHub\COMP2012H\HW9\main.exe

```

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
> Best,
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
