/*
Let n be the smallest integer such that the sum of digits of n is divisible by 5 as well as the sum of digits of (n + 1) is divisible by 5. What are the first two digits of n in the same order?
*/

#include <stdio.h>

int dsum(int n){
	int dig = 0, dsum = 0;
	while(n>0){
		dig = n%10;
		dsum+=dig;
		n=n/10;
	}
	return(dsum);
}

int main(){
	int n = 10, number;
	while(1){
		n+=1;
		if(dsum(n)%5 == 0 && dsum(n+1)%5 == 0){
			number = n;
			break;
		}
	}
	printf("%d", number);

	return 0;
}
