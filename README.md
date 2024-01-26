# PS5: DNA Alignment

## Contact
Name: Patricia Antlitz
Section:
Time to Complete:

Partner: N/A

## Description
The project aims to implement a DNA sequence alignment program using the Edit Distance algorithm. The main.cpp file takes two input DNA sequences, computes the optimal edit distance, and outputs the result along with the alignment details.

### Features
The alignment is done using a dynamic programming approach, filling in a matrix to find the optimal edit distance. The data structure used is a 2D vector to represent the matrix.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

When it comes to executing large input file size the process exits. For example running case 100,000, the code breaks this is attributed to the processing power of my laptop.

### Extra Credit
Anything special you did.  This is required to earn bonus points.


## Analysis

### Example
Do one additional test case by hand. It should be constructed in such a way that you know the correct  output before running your program on it, and it should be a "corner case" that helps check if your program handles all special situations correctly. 



Please list:
 - a copy of the test case input
 - the expected test case output
 - whether your program ran correctly on it or not
 - optionally, any other remarks
-Input Test case
    AGCT
    ACGT
-Expected Output
    Optimal Alignment:
    A G C - 2
    A C G 1
    Edit distance = 1



### Specs
Your Computer
Memory: (ex: 8gb, DDR4)
Processors: (Intel® Core™ i5-3437U CPU @ 1.90GHz × 4)

Partner's Computer
Memory: (ex: 8gb, DDR4)
Processors: (ex: i5-8500 @ 3.00 GHz x6)

### Runs
Fill in the table with the results of running your code on both your and your partner's computers.

| data file     | distance | memory (mb) | time (seconds) | partner time |
|---------------|----------|-------------|----------------|--------------|
|ecoli2500.txt  |  118     |   23.97     |   1.89757      |              |
|ecoli5000.txt  |  160     |   95.55     |   6.31619      |              |
|ecoli7000.txt  |  194     |   187.2     |   12.486       |              |
|ecoli10000.txt |  223     |   381.8     |   30.1712      |              |
|ecoli20000.txt |  3135    |   1491      |   117.04       |              |
|ecoli28284.txt |  8394    |   2981      |   233.365      |              |

Here is an example from another computer for some of the files.

| data file    | distance | time (s) |
|--------------|----------|----------|
|ecoli2500.txt |      118 |    0.171 |
|ecoli5000.txt |      160 |    0.529 |
|ecoli7000.txt |      194 |    0.990 |
|ecoli10000.txt|      223 |    1.972 |
|ecoli20000.txt|     3135 |    7.730 |

### Time
Assume the two strings are the same length (M = N).  By applying the doubling method to the data points that you obtained, estimate the running time of youu program in seconds as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input your program can handle if it is limited to one day of computation.

Provide a brief justification/explanation of how you applied the doubling method, and if you data seems not to work, describe what went wrong and use the sample data instead.

The doubling method involves increasing the input size by a factor of 2 and observing how the running time scales.

Find the ratio of  consecutive running times (larger/smaller) to estimate b in the formula a * N^b.
    a= (time[i]/N^b)
    b=(log(time[i+1]/time[i])/(distance[i+1]/distance[i]))/number if processes
 - a = 0.000275
 - b = 2.718
 -The So, the estimated polynomial function is 0.012⋅N^2.067
 -The largest N to handle one day we set a⋅N^b = 86,400(seconds ina a day) 
 Therefore, the largest  N the program can handle in one day is approximately 

 - largest N =  131,300

### Memory
Assume the two strings are the same length (M = N).  Look at your code and determine how much memory it requires as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input size your computer can handle given the amount of memory available.
 - a = 2.378
 - b = 0.000508
 - largest N = 340,500.


## Pair Programming
If you worked with a partner, do you have any remarks on the pair programming method? E.g., how many times did you switch, what are the tradeoffs of driving vs. navigating, etc.?



## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

