/********************************************************************************/
/*																				*/
/*									HIKMET TUTUNCU								*/
/*								CSE 102   ASSINGMENT #4							*/
/*									  141044054									*/
/*																				*/
/********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VALUE 100	/*	Maximum number of "values.txt" 						*/
#define MAX_POL 1000	/*	Maximum number of chars in "polynomial.txt"			*/

/*	The program takes values from "values.txt" file. And then, evaluates them		*/
/*	with "polynomial.txt" file. At the end, evaluations prints to "evalutions.txt"	*/

void Evaluator(double values[],char polynomial[],int num_of_value,int num_of_pol);


int main()
{
	int num_of_value=0,			/*	num_of_value means how many values in "values.txt		*/
		num_of_pol = 0;			/*	num_of_pol means how many characters in "polynomial.txt"*/

	double values[MAX_VALUE];	/*	Initializing of values array, max size of value is MAX_VALUE*/
	char polynomial[MAX_POL];	/*	Initializing of polynomial array, max size is MAX_POL		*/

	FILE *input_value = fopen("values.txt","r");	/*	values reads from file "values.txt" file */
	FILE *input_polynomial = fopen("polynomial.txt","r");/*polynomial reads from "polynomial.txt"*/

	while( fscanf(input_value,"%lf",&values[num_of_value]) !=EOF )
	{
		/*	values reads from file and assigns to values array with double						 */
		num_of_value++;	/*	Finding how many values in "values.txt" file 						 */
	}

	while( fscanf(input_polynomial,"%c",&polynomial[num_of_pol]) != EOF )
	{
		/*	polynomial characters reads from file and assigns to polynomial array with char 	 */
		num_of_pol++; /*	Finding how many characters in "polynomial.txt"						 */
	}

	Evaluator(values,polynomial,num_of_value,num_of_pol);	/*	Calling function: Evaluator		 */

	fclose(input_value);	
	fclose(input_polynomial);

	return 0;
}

/*	The function,Evaluator evaluates every values with polynomial expressions	*/
/*	and prints the evaluations to file "evaluations.txt" 						*/
void Evaluator(double values[],char polynomial[],int num_of_value,int num_of_pol)
{
	FILE *output = fopen("evaluations.txt","w");/*	Creates a new file program will write */
	int i=0,row=0,counter=0,j=0;	/*	counters of loops								  */
	char array[MAX_POL/3][MAX_POL]; /*	Initializing of two dimensional array			  */
	char power_sign,operator,x_val,junk_ch;	
	double  coefficent = 1.0,
			power_val = 0.0,
			power = 0.0,
			result = 0.0;
	
	/*	This loop creates a two dimensional array. Assigns polynomials to this array.
	The array includes polynomial expressions.Loop seperates polynomials.
	Defining the array like this :    	
	5x
	+3x
	-4x^2
	+8x^3	*/
	
	array[0][0] = 0;		/*The array is starting with 0 at first					*/
	for(i=0; i<num_of_pol; i++)
	{
		
		if( polynomial[i] == '+' || polynomial[i] == '-')
		{
			row++;	/*	If the program sees '+' or '-' operations, jumps a row		*/
			counter=0;
		}
		array[row][counter] = polynomial[i];	/*	Assigning the 2d array. 		*/
		counter++;
		
	}

	/*	The program initialize 2d array . But if polynomial expressions starts with 
	*	'-', program jumps automatically a row. So the solve is "starter" point. 
	*	If first value of array is 0, it means program had jumped a row.So,
	*	if the array[0][0] = 0 , program will be start the second row.
	*	Program will start first row the other situations.							*/
	int starter;
	if( array[0][0]==0 )			
		starter = 1;
	else
		starter = 0;

	/*	This loop evaluates every value of values[] array with created from polynomials[]
		array. Program uses array[][] in this loop. Take values from values[] one by one,
		and evaluates them for polynomials. At the end, prints them to file.			*/
	for( i=0; i<num_of_value; i++)	
	{
		coefficent = 1.0;
		for( j=starter; j<=row; j++)
		{
			coefficent = 1.0;
			coefficent = 1.0;
			if( j==0 && starter == 0)	/* Starting point is 0, program starts here		*/
			{				/* So, program scans them seperately. 					 	*/
				/*	scans rows from array[][], and assigns them like: 
					a double coefficent/x value/power sign/power value  		 		*/
				sscanf(array[j],"%c%c%lf",&junk_ch,&junk_ch,&power_val);
				sscanf(array[j],"%lf%c%c%lf",&coefficent,&x_val,&power_sign,&power_val);
				if( power_val == 0.0)
				{	/* If the power value=0, program returns it 1.0					*/
					power_val = 1.0;/*	Because if it was 0, program will work wrong*/
				}

				if ( coefficent == 0.0)
				{	/*	If the coefficent=0, program returns it 1.0					*/
					coefficent = 1.0;
				}
				power = pow(values[i],power_val);/* power of value with power value */
				result = result + coefficent * power ;/* Calculating result 		*/
				power_val = 0.0;	/*	Power value must be zero at the end			*/
			}
			else
			{
				/*	Sometimes the polynomials can be like "x^3", it means there is a 
					coefficent and it is 1. But in this situation, program can't know
					that. So scanning can be fail cause of sliding characters.
					And scanning can not assigns end of the row,power value to anything.
					So the program controls that like this.
					"Two Scanning".
					Scan first, there is no coefficent,
					scan finally, there is a coefficent.
					So program can catch the power value rightly.						*/
				sscanf(array[j],"%c%c%c%lf",&junk_ch,&junk_ch,&junk_ch,&power_val);
				sscanf(array[j],"%c%lf%c%c%lf",&operator,&coefficent,&x_val,&power_sign,&power_val);
				
				if( power_val == 0.0)
					power_val = 1.0;
				
				if ( coefficent == 0.0)
					coefficent = 1.0;
				
				power = pow(values[i],power_val);	/*	Calculating power value */
				if( operator == '+')
				{	/*	If operator is '+', program adds the results.			*/
					result = result + coefficent * power;
				}
				else if( operator == '-' )
				{	/*	If operator is '-', program subtract results.			*/
					result = result - (coefficent * power);
				}
				power_val = 0.0;
			}
		}
		fprintf(output,"%.2lf\n",result);	/*	Printing evaluations to file 	*/
		result = 0.0;
	}
	
	fclose(output);
}