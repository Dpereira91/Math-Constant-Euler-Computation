/* 
 * File:   assignment.c
 * Author: Darilys Pereira
 * Created on February 6, 2016, 5:24 PM
 * 
 * 
 * This program computes the value of the base of natural log (e) with an  
 * accuracy of 10 decimal places.
 * To calculate this value I'll use the Taylor Series formula 
 *      ∞
    e = ∑   1/n!
        n=0
 
 * The program will output the value found with the 10th digit accuracy, the
 * number of times factorial is calculated, and the constant Euler 
 * provided on the math.h library .
 
 
 * "I hereby certify that this collective work is my own and none of it is
 *  the work of any other person or entity. DPL“  
 */

//-------------------------INCLUDES--&--DEFINES----------------------------------
#include <stdio.h>
#include <math.h> // allows use of constant M_E

#define DECIMALPLACE 0.000000001 //used to determine accuracy to 10th dec place




/*-------------------------Pseudocode:------------------------------------------
1.Compute the value of e from 1/0! to unknown until 10 digit accuracy reached.  
2.Keep 2 variables with the computed value of e: one with the current 
 * computation and one with the previous calculated value.
3.Compare the difference of these 2 variables so that when I subtract
 *  one from the other the difference is less than the 10th significant digit
 *  ((current – previous ) < 0.000000001)
4.Repeat step 1-3 until 10th accuracy digit is reached
5.Print e from calculation, e from math.h and number of times factorial was
 * calculated
 */


int main(int argc, char** argv) {

    
    //Declaration and initialization
    double previousEuler = 0.0; //
    double currentEuler = 1.0;//initialize to 1 to reflect 1/0! = 1
    int factorialCounter = 0; //counts the # of iterations & assists 
    //calculate factorial
    long factorial = 1; //initial factorial value 1!= 1
    int reachSolutionFlag = 0; // 1 means finished

    
    
    
    while (reachSolutionFlag == 0) {
        factorialCounter++;
        factorial = factorialCounter * factorial;
        currentEuler += (1.0 / factorial); // Taylor's series execution
        if ((currentEuler - previousEuler) < DECIMALPLACE) {//10 accuracy digit 
            reachSolutionFlag = 1; 
        }

        previousEuler = currentEuler;//reset value
    }//end of while 

    
    
    //OUTPUT
    printf("Number of times the formula needs to be applied: %i\n",
            factorialCounter);
    printf("Value of my calculations of Euler: %1.9f\n", previousEuler);
    printf("Value of Euler from <math.h>:      %1.9f\n", M_E);

    return 0;
}//end of main

//Euler value 2.71828182845904523536028747135266249775724709369995
