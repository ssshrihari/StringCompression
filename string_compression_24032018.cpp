/*
AUTHOR:SHRIHARI SHETTY
DATE:24/03/2018
PROBLEM:GIVEN A STRING IN LOWER CASE OR UPPERCASE, MAY OR MAY NOT HAVE REPEATED CHARACTERS IN 
CONTINUOUS ORDER,WRITE A PROGRAM WHICH COMPRESSES THE STRING AND OUTPUTS THE SINGLE OCCURANCE
AND ITS FREQUENCY IN ORIGINAL STRING.
NOTE:CONSECUTIVE OCCURENCE OF A CHARACTER WILL BE NOT MORE THAN 9.
INPUT:abcd
OUTPUT:a1b1c1d1

INPUT:aaabbc
OUTPUT:a3b2c1

INPUT:a
OUTPUT:a1

TimeComplexity:O(n)
SpaceComplexity:1
Language:C
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//This Function Compresses the String and returns the Compressed the String
char *compress_string(char *input_string)
{
	//VARIABLES 
	unsigned long int *count_freq_letter=(unsigned long int*)calloc(52,sizeof(unsigned long int));
	int count_occurence=1,index_i,index_k=0;
	//LOOP TO IDENTIFY AND STORE THE LETTERS PRESENT
	//AND THE NUMBER OF TIMES IT HAS OCCURED
	for(index_i=0;index_i<strlen(input_string);index_i++)
	{
		//LOOP RUNS UNTILL WE GET DIFFERENT CHARACTER FROM THE CURRENT ith CHARACTER
		if(input_string[index_i]!=input_string[index_i+1])
		{
			//STORE THE LETTER ASCII VALUE IN count_freq_letter AT ith POSITION IN ARRAY
			count_freq_letter[index_k]=(int)input_string[index_i];
			//STORE THE LETTER OCCURENCE VALUE IN count_freq_letter AT i+1 POSITION IN ARRAY
			count_freq_letter[index_k+1]=count_occurence;
			//INCREMENT THE INDEX BY 2 AS WE USED TWO POSITIONS IN THE count_freq_letter ARRAY
			index_k+=2;
			//REINITIALISE THE count_occurence
			count_occurence=1;
			}
		//IF SAME CHARACTERS ARE PRESENT IN ADJACENT POSTITIONS	
		else
		//INCREMENT THE OCCURENCE OF THE CHARACTER 
		    count_occurence++;
	}
	//LOOP TO COMPUTE TH CHARACTER VALUE FROM THE ASCII VALUE AND STORE BACK IN input_string
	for(index_i=0;index_i<index_k;index_i+=2)
	{
		//CHARACTER REPLACEMENT
		input_string[index_i]=(char)count_freq_letter[index_i];
		//COUNT OF CHARACTER REPLACEMENT
		input_string[index_i+1]=(char)(count_freq_letter[index_i+1]+'0');
	}
	//NULL TERMINATION
	input_string[index_i]='\0';
	//FREE THE MEMORY
	free(count_freq_letter);
	return input_string;
}
//DRIVER PROGRAM
int main()
{
	char *input_string=(char*)malloc(sizeof(char)*100000);
	scanf("%s",input_string);
	//START TIME
	clock_t begin = clock();
	//OUTPUT
	printf("%s",compress_string(input_string));
	//FREE THE MEMORY
	free(input_string);
	//END TIME
	clock_t end = clock();
	//CLOCKS_PER_SEC IS A VARIABLE IN time.h FILE
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n\nTime to Execute is:%Lf",time_spent);
	getchar();
	return 0;
}
//OUTPUT RESULT
/*
aaaaaaaaabbbbbbbbbcccccccccddddddddeeeeeeeeefffffffffggggggggghhhhhhhhhjjjjjjjjjkkkkkkkkklllllllllpppppppppiiiiiiiiiyyyyyyyyy
a9b9c9d8e9f9g9h9j9k9l9p9i9y9

Time to Execute is:0.000000

*/
