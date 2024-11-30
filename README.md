# C Assembly Interface LBYARCH Machine Project

A program that calculates the acceleration of multiple cars given `initial velocity (km/h)`, `final velocity (km/h)`,  and `time (s)` 

## Project details

Authors: Rendell Ngo & Rydel Lim
Date Completed: 12/1/24

## Installation

Download of clone this project into a directory of your choice

## Running

For Visual Studio users, run or debug the program using your selected compiler. Note: you will need `nasm.exe` in your PATH for this to work. This will build the program and wait for input. 

For building in a terminal with make, run `make` then `./main.exe` to achieve the same effect.

### Input format
Input format is as follows:
- one integer Y representing the number of rows of input  
- Y * 3 numbers representing the Vi, Vf, and T of each row (in that order)

## Execution times

| Y        | Avg    | Highest | Lowest |
| -------- | ------ | ------- | ------ |
| 10       | 0      | 0       | 0      |
| 100      | 0      | 0       | 0      |
| 1000     | 0      | 0       | 0      |
| 10000    | 0.37   | 1       | 0      |
| 100000   | 2.67   | 5       | 0      |
| 1000000  | 29.17  | 40      | 24     |
| 10000000 | 286.77 | 321     | 259    |

### Analysis

As expected, the runtime gets longer the more function calls there are. Based on the chart, it grows linearly as can be seen with in the average times. 

### Screenshots


