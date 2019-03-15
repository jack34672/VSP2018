#include<stdio.h>

int findroad(int a, int b);

int s[100][100] = {0};
int check[100] = {0};
int n;

int main(){
	
	int i, j, k, road, maxroad=0, min=100, max = 0;
	int S[10000];
	int roadnum[100] = {0};
	char c='0';

	for(i=0; c!=' '; i++){
		scanf("%c", &c);
		S[i] = c - 48;
	}
	S[i-1] = '\0';

	scanf("%c", &c);
//	scanf("%c", &c);
	n = c - 48;
	
	k=0;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			s[i][j] = S[k];
			k++;
		}
	}

	for(i=0; i<n; i++){
		maxroad = 0;
		for(j=0; j<n; j++){
			if(i!=j){
				road = findroad(i, j);
//				printf("findroad(%d, %d) = %d\n", i, j, road);
				if(road>maxroad){
					maxroad=road;
				}
			}
		}
		roadnum[i] = maxroad;
		if(roadnum[i]<min){
			min = roadnum[i];
		}
//		printf("roadnum[%d] = %d\n", i, roadnum[i]);
	}
//	printf("%d\n", min);
	for(i=0; i<n; i++){
		if(roadnum[i]==min){
			printf("%d ", i);
		}
	}



/*	printf("\n");
	for(j=0; j<n*n; j++){
		printf("%d, ", S[j]);
	}
	printf("%d\n", n);

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d, ", s[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<n; i++){
		printf("%d, ", roadnum[i]);
	}
*/	
	return 0;
}

int findroad(int a, int b){
	int i, min = 100, steps = 0;
	int road[100];

	if(s[a][b]==1){
		return 1;
	}else{
		for(i=0; i<n; i++){
			if((s[a][i]==1)&&(a!=i)&&(check[a]==0)){
				check[a]=1;
				road[i] = 1 + findroad(i, b);
				check[a]=0;
			}else{
				road[i] = 100;
			}
		}
		for(i=0; i<n; i++){
			if(road[i]<min){
				min = road[i];
			}
		}
		return min;
	}

}
