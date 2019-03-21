/********************************************************************************************/
/*                                 CSE 102 Computer Programming in C                        */
/*											    */												*/
/*                                         HIKMET TUTUNCU                                   */
/*                                HW 03                    	                            */
/*                                                                                          */
/********************************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 250		/*		Maximum length of rows			 		*/
#define MAX_ROW 100		/*		Maximum row number 					*/

void Xanthos_finder(char Xanthos[],char main_array[][MAX_LEN],int row);
void Patara_finder(char Patara[],char main_array[][MAX_LEN],int row);
void Myra_finder(char Myra[],char main_array[][MAX_LEN],int row);
void Arycanda_finder(char Arycanda[],char main_array[][MAX_LEN],int row);
void Phaselis_finder(char Phaselis[],char main_array[][MAX_LEN],int row);

int main()
{
	int row;
	char main_array[MAX_ROW][MAX_LEN];		/*	The program takes strings from file and assigns to main_array	*/
	
	FILE *input = fopen("input.txt","r");	/*						File reads from input.txt 					*/

	char Xanthos[] = "Xanthos";				/*							Initializing  							*/
	char Patara[] = "Patara";				/*								of									*/
	char Myra[] = "Myra";					/*			           		   Words								*/
	char Arycanda[] = "Arycanda";
	char Phaselis[] = "Phaselis";


	row=0;
	while( fgets(main_array[row],MAX_ROW*MAX_LEN,input) )		/*	Assigns	strings input.txt file to main_array	*/
	{
		row++;													/*	Characters assigns to rows and columns			*/
	}
	
	Xanthos_finder(Xanthos,main_array,row);						/*			Calling 								*/
	Patara_finder(Patara,main_array,row);						/*				  of								*/
	Myra_finder(Myra,main_array,row);							/*				   the								*/
	Arycanda_finder(Arycanda,main_array,row);					/*					Functions						*/
	Phaselis_finder(Phaselis,main_array,row);


	fclose(input);
	return 0;
}


/*				Initializing of Functions				*/
/*			Each function finds about Words 			*/
/*		Finds words if they horizontal or Vertical 		*/
/*			and finds coordinates of words 				*/
/*				then prints to the screen				*/	

void Xanthos_finder(char Xanthos[],char main_array[][MAX_LEN],int row)
{
	int j,k,p=0;									/*		Initializing of counters				 	*/
	int h1=0,h2=0;									/*	h1 and h2 means horizontal coordinate 1 and 2	*/
	int v1=0,v2=0;									/*	v1 and v2 means vertical coordinate 1 and 2		*/
	
	/*	The function controls horizontal words at first.	*/
	for(j=0; j<row; j++)
	{
		for(k=0; k<strlen(main_array[j]); k++)
		{
			if(Xanthos[p]==main_array[j][k])		/*	If p of Word matches main_array					*/
			{
				p++;	
				if(p==strlen(Xanthos))				/*	If p reaches length of Word 					*/
				{
					h2 = k - strlen(Xanthos) +2;	/*	h2 must be like this because length of word 	*/
					break;							/*	must be +2 and it must subtract from k 			*/
				}
				else if(Xanthos[p]!=main_array[j][k+1])
				{
					p=0;						/*	If length of word is over, program assigns counter 0*/
				}

			}
			
			
		}
		if(p==strlen(Xanthos))					/*	h1 must be +1 of j because j starting from 0	*/
		{
			h1 = j + 1;							/*	if p reaches length of word, program breaks		*/
			break;
		}
	}
	/*	And then, the function controls vertical Word 		*/

	p = 0;
	for(j=0; j<row; j++)
	{
		for(k=0; k<strlen(main_array[j]); k++)
		{
			if(Xanthos[p]==main_array[k][j])	/*	If p of Word matches main_array					*/
			{
				
				p++;
				if(p==strlen(Xanthos))			/*	If p reaches length of Word 						*/
				{								
					v2 = j+1;					/*	v2 must be +1 of j because j starting from 0		*/
					break;						/*	Rows and columns start 1, so program does +1		*/
				}
				else if(Xanthos[p]!=main_array[k+1][j])
				{
					p=0;						/*	If length of word is over, program assigns counter 0*/
				}
				
			}
			
		}
		

		if(p==strlen(Xanthos))
		{
			
			v1 = k-strlen(Xanthos) +2;
			break;
		}

	}

	/*	If coordinates of word is 0 and 0, the program doesn't prints that			*/
	/*	But coordinates of word is not 0 and 0, program prints which is not zero	*/
	/*					Horizontal or Vertical 										*/
	if(h1!=0 && h2!=0)
	{
		printf("Xanthos (%d,%d) Horizontal\n",h1,h2);
	}
	else{
		printf("Xanthos (%d,%d) Vertical \n",v1,v2);
	}
}

void Patara_finder(char Patara[],char main_array[][MAX_LEN],int row)
{
	int j,k,p=0;
	int h1=0,h2=0;
	int v1=0,v2=0;
	for(j=0; j<row; j++)
	{
		for(k=0; k<strlen(main_array[j]); k++)
		{
			if(Patara[p]==main_array[j][k])
			{
				p++;
				if(p==strlen(Patara))
				{
					h2 = k - strlen(Patara) +2;
					break;
				}
				else if(Patara[p]!=main_array[j][k+1])
				{
					p=0;
				}

			}
			
			
		}
		if(p==strlen(Patara))
		{
			h1 = j + 1;
			break;
		}
	}

	p = 0;
	for(j=0; j<row; j++)
	{
		for(k=0; k<strlen(main_array[j]); k++)
		{
			if(Patara[p]==main_array[k][j])
			{
				
				p++;
				if(p==strlen(Patara))
				{
					v2 = j+1;
					break;
				}
				else if(Patara[p]!=main_array[k+1][j])
				{
					p=0;
				}
				
			}
			
		}
		

		if(p==strlen(Patara))
		{
			
			v1 = k-strlen(Patara) +2;
			break;
		}

	}

	if(h1!=0 && h2!=0)
	{
		printf("Patara (%d,%d) Horizontal\n",h1,h2);
	}
	else{
		printf("Patara (%d,%d) Vertical \n",v1,v2);
	}
}

void Myra_finder(char Myra[],char main_array[][MAX_LEN],int row)
{
	int j,k,p=0;
	int h1=0,h2=0;
	int v1=0,v2=0;
	for(j=0; j<row; j++)
	{
		for(k=0; k<strlen(main_array[j]); k++)
		{
			if(Myra[p]==main_array[j][k])
			{
				p++;
				if(p==strlen(Myra))
				{
					h2 = k - strlen(Myra) +2;
					break;
				}
				else if(Myra[p]!=main_array[j][k+1])
				{
					p=0;
				}

			}
			
			
		}
		if(p==strlen(Myra))
		{
			h1 = j + 1;
			break;
		}
	}

	p = 0;
	for(j=0; j<row; j++)
	{
		for(k=0; k<strlen(main_array[j]); k++)
		{
			if(Myra[p]==main_array[k][j])
			{
				
				p++;
				if(p==strlen(Myra))
				{
					v2 = j+1;
					break;
				}
				else if(Myra[p]!=main_array[k+1][j])
				{
					p=0;
				}
				
			}
			
		}
		

		if(p==strlen(Myra))
		{
			
			v1 = k-strlen(Myra) +2;
			break;
		}

	}

	if(h1!=0 && h2!=0)
	{
		printf("Myra (%d,%d) Horizontal\n",h1,h2);
	}
	else{
		printf("Myra (%d,%d) Vertical \n",v1,v2);
	}
}

void Arycanda_finder(char Arycanda[],char main_array[][MAX_LEN],int row)
{
	int j,k,p=0;
	int h1=0,h2=0;
	int v1=0,v2=0;
	for(j=0; j<row; j++)
	{
		for(k=0; k<strlen(main_array[j]); k++)
		{
			if(Arycanda[p]==main_array[j][k])
			{
				p++;
				if(p==strlen(Arycanda))
				{
					h2 = k - strlen(Arycanda) +2;
					break;
				}
				else if(Arycanda[p]!=main_array[j][k+1])
				{
					p=0;
				}
			}
		}
		if(p==strlen(Arycanda))
		{
			h1 = j + 1;
			break;
		}
	}

	p = 0;
	for(j=0; j<row; j++)
	{
		for(k=0; k<strlen(main_array[j]); k++)
		{
			if(Arycanda[p]==main_array[k][j])
			{
				p++;
				if(p==strlen(Arycanda))
				{
					v2 = j+1;
					break;
				}
				else if(Arycanda[p]!=main_array[k+1][j])
				{
					p=0;
				}
			}
		}
		

		if(p==strlen(Arycanda))
		{
			
			v1 = k-strlen(Arycanda) +2;
			break;
		}
	}

	if(h1!=0 && h2!=0)
	{
		printf("Arycanda (%d,%d) Horizontal\n",h1,h2);
	}
	else{
		printf("Arycanda (%d,%d) Vertical \n",v1,v2);
	}
}

void Phaselis_finder(char Phaselis[],char main_array[][MAX_LEN],int row)
{
	int j,k,p=0;
	int h1=0,h2=0;
	int v1=0,v2=0;
	for(j=0; j<row; j++)
	{
		for(k=0; k<strlen(main_array[j]); k++)
		{
			if(Phaselis[p]==main_array[j][k])
			{
				p++;
				if(p==strlen(Phaselis))
				{
					h2 = k - strlen(Phaselis) +2;
					break;
				}
				else if(Phaselis[p]!=main_array[j][k+1])
				{
					p=0;
				}

			}
		}
		if(p==strlen(Phaselis))
		{
			h1 = j + 1;
			break;
		}
	}

	p = 0;
	for(j=0; j<row; j++)
	{
		for(k=0; k<strlen(main_array[j]); k++)
		{
			if(Phaselis[p]==main_array[k][j])
			{
				p++;
				if(p==strlen(Phaselis))
				{
					v2 = j+1;
					break;
				}
				else if(Phaselis[p]!=main_array[k+1][j])
				{
					p=0;
				}
			}
		}
		

		if(p==strlen(Phaselis))
		{
			v1 = k-strlen(Phaselis) +2;
			break;
		}
	}

	if(h1!=0 && h2!=0)
	{
		printf("Phaselis (%d,%d) Horizontal\n",h1,h2);
	}
	else{
		printf("Phaselis (%d,%d) Vertical \n",v1,v2);
	}
}
