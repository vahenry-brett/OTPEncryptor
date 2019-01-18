/*
 *Brett Henry
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int arg, char *argv[])
{
		
		if(arg!=5)//checks number of arguments passed
		{
			printf("Error!!!!! Arguments must be as follows: filename1, filename2, ENCRYPT/DECRYPT, key\n");
			return 0;
		}
		FILE *fin;
		FILE *fout;
		fout = fopen(argv[2],"w");//creates output file
		fin = fopen(argv[1],"r");//creates input file
		
		if(fin == NULL)//checks if file name passed exists
		{
			printf("Unable to open file\n");
			return 1;
		}

		int c;
		
		if(strcmp(argv[3],"ENCRYPT")==0)//Checks the mode passed
		{
			printf("Encrypting........\n");
		}
		else if(strcmp(argv[3],"DECRYPT")==0)
			printf("Decrypting........\n");
		else
		{
			printf("Error!! Third argument must be either ENCRYPT or DECRYPT");
			return 1;
		}

		srandom(*argv[4]);//seeds random number with key passed
		
		/*Loop below reads each char from input file individualy and encrypts/decrypts it, then writes it back to the output file
 		 *
 		 */ 
		while((c=fgetc(fin)) != EOF)
		{
			int r = random()%97;//getting random number for this char
			if(c=='\t')
				c= 0;
			else if(c=='\n')
				c=1;
			else
			{
				c=c-30;
				c = toupper(c);
			}
			if(strcmp(argv[3],"ENCRYPT")==0)	
				c = (c+r)%97;
			else
				c = (c + 97 - r) %97;

				
			if(c==0)
				c='\t';
			else if(c==1)
				c='\n';
			else
				c = c+30;

			fputc(c,fout);
		}
		fclose(fin);//closing files
		fclose(fout);
		if(strcmp(argv[3],"ENCRYPT")==0)
			printf("Your file has been encrypted! and stored under:\n %s\n",argv[2]);
		else
			printf("Your file has be decrypted! a plain text version is now stored under: \n%s\n",argv[2]);


		return 0;
}
