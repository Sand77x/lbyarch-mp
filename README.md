# C Assembly Interface LBYARCH Machine Project

A program that calculates the acceleration of multiple cars given `initial velocity (km/h)`, `final velocity (km/h)`,  and `time (s)`.

## Project details

__Authors__: Rendell Ngo & Rydel Lim  
__Date Submitted__: 12/1/24  
__Video__: [https://youtu.be/MSQkEwf9_wk](https://youtu.be/MSQkEwf9_wk)

## Installation

Download or clone this project into a directory of your choice.

## Running

For Visual Studio users, run or debug the program using your selected compiler. Note: you will need `nasm.exe` and `gcc` in your PATH or compiler settings for this to work. This will build the program and wait for input.   

To generate samples, compile and run `make_samples.c` using any method and pass the amount of samples as a CLI argument. This creates a `sample_input.txt` that you can pipe into `main.exe`.

```
gcc make_samples.c -o make_samples.exe
```
After, to generate 100 samples for example, punch in: 
```
make_samples.exe 100
```
This will generate a valid random input that can be piped into main in sample_input.txt 

To compile the main C file and the asm file, enter the following commands.
```
gcc -c main.c -o main.o
nasm -fwin64 func.asm -o func.o
gcc main.o func.o -o main.exe
```
You can run main.exe manually as expected, punching in manual inputs, or you can pipe in sample_inputs.txt with the following command.
```
main.exe < sample_input.txt
```
__Note__: Both executables (main and make_samples) are in the `dist` folder, run them if you don't want to compile the source code manually.  

### Input format
Input format is as follows:
- one integer Y representing the number of rows of input  
- then Y * 3 numbers representing the Vi, Vf, and T of each row (separated by commas)
```
Ex.  
3  
0.0, 62.5, 10.1  
60.0, 122.3, 5.5  
30.0, 160.7, 7.8  
```

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

Note: we chose to include tests past Y=10,000 because the differences were barely noticable and it was difficult to make meaningful judgement otherwise.
As expected, the runtime gets longer the more function calls there are. Based on the chart, it grows linearly as can be seen with the average times. What is surprising is that even though Assembly is supposed to give programmers more control over the hardware, C code was still consistently faster. However, we did a preliminary test on a different, lower-end laptop, where the C code nearly tripled in execution time and Assembly code remained the same speed, becoming faster. This points to different methodologies being preferable based on the environment they are being executed in, and that one is not inherently better or more efficient than the other. 

### Testing

The files were tested using a batch script that ran each file 30 times for Y = 10 .. 10000000. The results were then manually calculated to find average and output ranges. The runs and times can be seen in `runs.txt`.

### Screenshots

![00A2160E-27EF-4D87-9001-A60CF9289872](https://github.com/user-attachments/assets/d71303a9-50eb-45cf-970c-aea6f65bb4d3)

![image](https://github.com/user-attachments/assets/29734281-324d-477a-b835-30ea29c3fb6c)

![image](https://github.com/user-attachments/assets/fd3592e6-01b9-4d05-8659-8083e5f59a10)

![image](https://github.com/user-attachments/assets/385b80f3-012a-4384-8f17-27f84d9f2ff8)


