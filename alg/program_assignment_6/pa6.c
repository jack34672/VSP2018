#include<stdio.h>
#include<math.h>

int main(){
	int s[1000] = {0};
	int tmp[100];
	int i, j, k, tens, l;
	char c=' ';
	for(i=0; c==' '; i++){
		scanf("%c", c);
		if(c=='-'){
			for(j=0; c==' '; j++){
				scanf("%c", c);
				if(c == '\0'){
					s[i+1] = '\0';
					break;
				}
				tmp[i] = c-48;
			}
			for(k=0; k<j; k++){
				tens = 1;
				for(l=0; l<j-k; l++){
					tens = tens*10;
				}
				s[i] = s[i] + tmp[k]*tens;
			}
			s[i] = 0-s[i];
		}else{
			for(j=0; c==' '; j++){
				scanf("%c", c);
				if(c == '\0'){
					s[i+1] = '\0';
					break;
				}
				tmp[i] = c-48;
			}
			for(k=0; k<j; k++){
				tens = 1;
				for(l=0; l<j-k; l++){
					tens = tens*10;
				}
				s[i] = s[i] + tmp[k]*tens;
			}
		}
		printf("%d, ", s[i]);

	}

	for(j=0; j<i-1; j++){
		printf("%d, ", s[j]);
	}


	return 0;
}

