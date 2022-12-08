#include<stdio.h>



void merge(int arr[] , int left , int mid , int right ){

	int n1 = mid - left + 1 ;
	int n2 = right - mid ;
	int L[n1],R[n2];

	for(int i = 0; i < n1; i++){
		L[i] = arr[left+i];
	}
	for(int j = 0; j < n2; j++){
		R[j] = arr[mid+1+j];
	}

	int i = 0, j = 0, k = left;

	while(i<n1&&j<n2){
		if(L[i] < R[j]){
			arr[k] = L[i];
			k++;i++;
		}
		else {
			arr[k] = R[j];
			k++;j++;
		}
	}

	while(i < n1){
		arr[k] = L[i];
		k++;i++;
	}
	while( j < n2){
		arr[k] = R[j];
		k++;j++;
	}
}
 
void mergeSort(int arr[],int left,int right){
	if(left < right){
		int mid = (left+right)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}


void main(){

	int arr[10], n;
	printf("How many numbers ? ");
	scanf("%d",&n);
	printf("Enter %d numbers : ");
	for(int i = 0 ; i  < n ; i++)
		scanf("%d",&arr[i]);
	printf("Before sorting : ");
	for(int i = 0; i < n ; i++)
		printf("%d\t",arr[i]);
	printf("\n");
	printf("After sorting : ");
	mergeSort(arr,0,n-1);
	for(int i = 0; i < n; i++)
		printf("%d\t",arr[i]);
	printf("\n");

}
