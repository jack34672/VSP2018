#include<stdio.h>

int main(){
	int S[100]={0};
	int s[100][100]={0};
	int tar[100]={0};
	int target, i, j, k, arrlength, tarlength, mod, binum, ans=1, tmp;
	char c=',';

	for(i=0; c==','; i++){
		scanf("%d%c", &S[i], &c);
	}
	scanf("%d", &target);
	arrlength = i;

	for (i = 0; i < arrlength; i++)    
	{
		for (j = 0; j < arrlength; j++) 
		{
			if (S[j] > S[i])       
			{
				int tmp = S[i];   
				S[i] = S[j];     
				S[j] = tmp;     
			}  
		}
	}

	for(i=0; i<arrlength; i++){
		if(S[i]>target){
			for(j=i; j<=arrlength; j++){
				S[j] = 0;
				arrlength--;
			}
		}
	}

	for(i=0; i<arrlength; i++){
		binum = S[i];
//			printf("%d = ", binum);
		for(j=0; binum != 0; j++){
			s[i][j] = binum%2;
//			printf("%d", s[i][j]);
			binum = binum/2;
		}
		s[i][j] = '\0';
//		printf("\n");
	}
	
	binum = target;
	for(j=0; binum!=0; j++){
		tar[j] = binum%2;
		binum = binum/2;
	}
	tar[j]='\0';
	tarlength=j;

	for(i=0; i<tarlength; i++){
		if(tar[i]==0){
			for(j=0; j<arrlength; j++){
				if(s[j][i]==1){
					S[j]=0;
					for(k=0; k<100; k++){
						s[j][k]=0;
					}
				}
			}
		}
	}
	
	int test = 0;

	for(i=0; i<tarlength; i++){
		if(tar[i]==1){
			for(j=0; j<arrlength; j++){
				if(s[j][i]==1){
					test = 1;
				}
			}
			if(test == 0){
				ans = 0;
			}
			test = 0;
		}
	}

/*
	for(i=0; i<arrlength; i++){
		for(j=0; j<10; j++){
			printf("%d, ", s[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<arrlength; i++){
		printf("%d, ", S[i]);
	}
	printf("%d\n", target);

	printf("ans = %d\n", ans);
*/
	if(ans==1){
		printf("true");
	}else{
		printf("false");
	}

	return 0;
}
