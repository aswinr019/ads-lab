#include<stdio.h>
int max(int arr[], int n){
	int i, max = 0;
	for(i = 0; i < n; i++){
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

int min(int arr[], int n){
	int i, min;
	min = arr[0];
	for(i = 0; i < n;i++){
		if(arr[i] < min)
			min = arr[i];
	}
	return min;
}

int sum(int arr[],int n){
	int i , sum = 0;
	for(i = 0; i< n; i++)
		sum = sum + arr[i];
	return sum;
}

float mean(int arr[], int n){
	int i , sum = 0;
	float avg;
	for(i = 0; i < n; i++)
		sum = sum + arr[i];

	avg = sum/n;
	return avg;
}

int count(int arr[],int n){
	int i , count = 0;
	for(i = 0; i < n;  i++)
		count++;
	return count;
}
	
void main(){
	int arr[10],i,choice,n = 10;
	printf("Enter array elements: ");
	for(i= 0; i < n; i++)
		scanf("%d",&arr[i]);
	do{
	printf("Enter a choice : \n1.Maximum\n2.Minimum\n3.Sum\n4.Mean\n5.Count\n");
	scanf("%d",&choice);
	switch(choice){
		case 1: {
				printf("The maximum value in the array is %d\n",max(arr,n));
				break;
			}
		case 2: {
				printf("The minimum element in the array is %d\n",min(arr,n));
				break;
			}
		case 3: {
				printf("The sum of elements in the array is %d\n",sum(arr,n));
				break;
			}
		case 4: {
				printf("The mean of elements in the array is %f\n",mean(arr,n));
				break;
			}
		case 5: {
				printf("The count of elements in the array is %d\n",count(arr,n));
				break;
			}
		default: {
				 printf("Wrong input\n");
			 }
	}
	}
	while(choice != 0);
}

	
