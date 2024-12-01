# C Assembly Interface LBYARCH Machine Project

A program that calculates the acceleration of multiple cars given `initial velocity (km/h)`, `final velocity (km/h)`,  and `time (s)`.

## Project details

__Authors__: Rendell Ngo & Rydel Lim  
__Date Submitted__: 12/1/24  
__Video__: https://youtu.be/RwF4CC1teZ4

## Installation

Download or clone this project into a directory of your choice.

## Running

For Visual Studio users, run or debug the program using your selected compiler. Note: you will need `nasm.exe` in your PATH for this to work. This will build the program and wait for input. 

For building in a terminal with make, run `make` then `./main.exe` to achieve the same effect.

### Input format
Input format is as follows:
- one integer Y representing the number of rows of input  
- then Y * 3 numbers representing the Vi, Vf, and T of each row (in that order)

## Execution times (in ms)

| Y        | Avg (x86-64) | Range (x86-64)  | Avg (C) | Range (C)       |
| -------- | ------------ | --------------- | ------- | --------------- |
| 10       | 0            | 0 - 0           | 0       | 0 - 0           |
| 100      | 0            | 0 - 0           | 0       | 0 - 0           |
| 1000     | 0            | 0 - 0           | 0       | 0 - 0           |
| 10000    | 0.33         | 0.00 - 1.00     | 0.20    | 0.00 - 1.00     |
| 100000   | 3.00         | 1.00 - 5.00     | 2.40    | 0.00 - 5.00     |
| 1000000  | 29.07        | 19.00 - 37.00   | 24.03   | 13.00 - 32.00   |
| 10000000 | 289.83       | 267.00 - 327.00 | 232.47  | 206.00 - 265.00 |
### Analysis

As expected, the runtime gets longer the more function calls there are. Based on the chart, it grows linearly as can be seen with the average times. 

### Screenshots

![image](https://github.com/user-attachments/assets/fd3592e6-01b9-4d05-8659-8083e5f59a10)

![image](https://github.com/user-attachments/assets/385b80f3-012a-4384-8f17-27f84d9f2ff8)


