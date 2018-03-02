#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void strrev(char * text){//not implemented in gcc so had to include||not a part of solution offcourse
	int l;
	int r;
	char temp;

	for(r=strlen(text)-1,l=0;r>l;l++,r--)
	{
		temp=text[l];
		text[l]=text[r];
		text[r]=temp;
	}
}


void XOR(char * i1,char *i2){
    int i;


    for(i=0;i<strlen(i2);i++){
        if(i1[i]==i2[i]){
            i1[i]='0';
        }
        else{
            i1[i]='1';
        }
    }
}

void append(char *input,char *divisor){
	int i;
 	int l;

	l = strlen(input);

	for(i=0;i<strlen(divisor)-1;i++){
		input[l+i]='0';
	}	
	
	input[l+i]='\0';
}

char * remainder(char * input,char *divisor){
	char *remainder;	

	remainder = strdup(input);

	

	while(strlen(remainder)!=strlen(divisor)-1){
	
	if(remainder[0]=='1')
		XOR(remainder,divisor);
	strrev(remainder);
	remainder[strlen(remainder)-1]='\0';
	strrev(remainder);
	}
	
	return remainder;

}

int main()
{
	char input[100],divisor[100];
	int i;
	char message[100];

	printf("Enter the input : \n");
	scanf("%s",input);
	
	printf("Enter the divisor : \n");
	scanf("%s",divisor);
	append(input,divisor);

	
	sprintf(message,"%d", atoi(input)+atoi(remainder(input,divisor))  );
	printf("%s\n",message);	
}
