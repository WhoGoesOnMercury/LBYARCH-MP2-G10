# LBYARCH-MP2-G10

# LBYARCH-MP2-G10

## Overview

This repository contains the machine project application of C to x86-64 interface. The main program, written in C, handles input and output macros, while the SIMD Assembly code manages the logic and arithmetic instructions. The project’s goal is to calculate the distances between coordinate points across two vectors. The program integrates C for high-level operations and assembly for performance-critical calculations.

## How to Run This Program

Follow these steps to compile and run the program:

1. **Ensure your environment has `nasm` and `gcc` installed.**
2. **Run the following commands sequentially in your terminal:**

   ```bash
   nasm -f win64 vector.asm
   gcc -c vectorc.c -o vectorc.obj -m64
   gcc vectorc.obj vector.obj -o vector.exe -m64
   vector.exe


# Analysis of run time of increasing vector sizes
The program was manipulated to automatically output the run time as well as the output of the vectors. Another file named randvector.c is the C interface used to randomize inputs and to manually manipulate the input sizes of the vectors. The C to x86-64 program was tested up until 2^24 and the further calculation of 2^30 resulted in the device of the programmers crashing. 

In the screenshot below, the total execution time of the program is displayed. The average run times rotated around these values. A factor that may affect the run time is the device and so it is necessary to say that the older device that was used in this experiment may have affected the result. When the application was ran together with printing the output, the execution time spiked massively. This is due to the fact that printing to the command line takes up more time than simply arithmetic instructions. Nevertheless, it is apparent the without the printing altogether, the program is efficient in dealing with the requirements.
![Screenshot (15)](https://github.com/user-attachments/assets/77afb774-a927-4338-b060-7e50279c01e3)

# Example outputs
1. Test Case from the project specs
   ![Screenshot (14)](https://github.com/user-attachments/assets/f6616a34-c1c4-4350-88f6-e08d69a42513)
2. Test Case with negative values (High run time is due to manual input)
   ![Screenshot (16)](https://github.com/user-attachments/assets/016f0ce0-2da9-4446-92b9-193954b9bcb9)



