#include <stdio.h>
#include <string.h>

int main(void){
	int i, j, mstrl=0, bagstrl=0, twosemi = 0;
	int changebag = -1;
	char changebagchar = 'A';
	char mainS[1000];
	char bag[1000];
	char c;
	for(i=0; twosemi < 2; ){
		scanf("%c", &c);
		if(twosemi == 1){
			mainS[i] = c;
			i++;
			mstrl++;
		}
		if(c == '"'){
			twosemi++;
		}
	}
	twosemi = 0;		
	for(i=0; twosemi < 2; ){
		scanf("%c", &c);
		if(twosemi == 1){
			bag[i] = c;
			i++;
			bagstrl++;
		}
		if(c == '"'){
			twosemi++;
		}
	}
	mstrl--;
	bagstrl--;

	for(i=0; i<mstrl; i++){
		for(j=0; j<bagstrl; j++){
			if(mainS[i]<bag[j]){
				if(bag[j]>changebagchar){
					changebag = j;
					changebagchar = bag[j];
				}
			}
		}
		if(changebag != -1){
			mainS[i] = bag[changebag];
			bag[changebag] = 'A';
		}
		changebag = -1;
		changebagchar = 'A';
	}

	printf("String expected = \"");
	for(i=0; i<mstrl; i++){
		printf("%c", mainS[i]);
	}
	printf("\"\n");

	return 0;
}
