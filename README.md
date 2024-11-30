# C Assembly Interface LBYARCH Machine Project

A program that calculates the acceleration of multiple cars given `initial velocity (km/h)`, `final velocity (km/h)`,  and `time (s)` 

## Project details

__Authors__: Rendell Ngo & Rydel Lim  
__Date Submitted__: 12/1/24  
__Video__: https://youtu.be/RwF4CC1teZ4

## Installation

Download of clone this project into a directory of your choice

## Running

For Visual Studio users, run or debug the program using your selected compiler. Note: you will need `nasm.exe` in your PATH for this to work. This will build the program and wait for input. 

For building in a terminal with make, run `make` then `./main.exe` to achieve the same effect. To make samples, run `make samples N_SAMPLES=<number>` where `number` is the amount of samples you want. Afterwards, type `main.exe < sample_input.txt` to run the newly generated samples. A batch file called `run.bat` also exists if you want to see program execution times for multiple Y values.

### Input format
Input format is as follows:
- one integer Y representing the number of rows of input  
- Y * 3 numbers representing the Vi, Vf, and T of each row (in that order)

## Execution times (in ms)

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

![image](https://github.com/user-attachments/assets/fd3592e6-01b9-4d05-8659-8083e5f59a10)

![image](https://github.com/user-attachments/assets/385b80f3-012a-4384-8f17-27f84d9f2ff8)


