# Maximum Voltage Problem
## Description
This is a coding challenge where I found the maximum voltage in a setting where cables need to be connected to ports.
You are given a set of cables and ports, and each cable produces a different voltage when connected to a different port.
To find the maximum voltage, you need to connect each cable to a different port.

## Problem Statement
The Maximum Voltage problem is a minimum-cost maximum-flow (MCMF) problem where the goal is to maximize the voltage by connecting the cables to the ports.
You are given a set of test cases, and you need to model them using cost and capacities on each edge, and then solve the problem using the MCMF algorithm.

## Solution Guidelines
To solve the problem, you need to model the test cases using MCMF approach, which requires cost and capacities on each edge.
After the modeling is complete, you can use the algorithm for MCMF problems to find the maximum voltage.
The algorithm needs to find negative cycles. See the code and explanation in this [link](https://konaeakira.github.io/posts/using-the-shortest-path-faster-algorithm-to-find-negative-cycles.html).

## Input and Output
* Each input file contains several test cases and each test case consists of a matrix that specifies the output voltage when a cable is plugged into a port.
* The first line of the input file contains an integer T, that denotes the number of test cases in this input file.
* The next line contains another integer N which is the number of cables (and ports) in the next test case.
* The subsequent N lines denote an N × N integer matrix V, in which Vij is the output voltage when the cable i is plugged into port j.
* The rest of the lines denote other test cases, where each has the same format: an integer N and an N × N integer matrix V.
* The output file is expected to contain the maximum voltage to run Bat-Signal for each test case in the input file in a separate line. 
* The correct output file should show the maximum voltage for each test case.

![image](https://user-images.githubusercontent.com/64011660/231547253-eab7b12b-aee2-4c66-bee1-050e60d9c489.png)

A graph representation (left) and a perfect matching (right) with maximum voltage for the test cases in the sample input file. You should use a different graph representation to
model the problem with MCMF.

## Running the Program
This code reads the name of the input and output files from the command line. You can run the code as follows:

```
g++ *.cpp -std=c++11 -o project4
./project4 <inputFile> <outputFile>
```

## Contributing
If you have any suggestions or find any issues with the code, please feel free to contribute to the project by opening a pull request or creating an issue.

## Credits
This is the fourth project of CMPE250 Data Structures and Algorithms class in Fall 2020 
