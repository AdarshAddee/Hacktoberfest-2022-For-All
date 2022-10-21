#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merging(long long left ,long long right , long long middle, long long *arr);
void bubblesort(long long int n,long long int *arr){
	for (int i=0 ;i<n-1;i++){
		for (int j=0;j<n-1-i;j++){
			if (arr[j]>arr[j+1]){
				int temp;
				temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void mergesort(long long int left , long long right, long long *arr){
	long long middle =(left +right)/2;
	if (left<right){
		mergesort(left,middle,arr);
		mergesort(middle+1,right,arr);
		merging(left,right,middle,arr);
	}

}
void merging (long long left,long long right,long long middle,long long *arr){
	long long int leftArraySize=middle-left+1;
	long long int rightArraySize=right-middle;
	long long * leftArray=(long long *)(malloc(sizeof(long long )*leftArraySize));
        long long * rightArray=(long long *)(malloc(sizeof(long long )*rightArraySize));
	for (long long int i=0;i<leftArraySize;i++){
		leftArray[i]=arr[left+i];
	}
	for (long long int i=0;i<rightArraySize;i++){
		rightArray[i]=arr[middle+i+1];
	}
	long long leftArrayIndex=0,rightArrayIndex=0;
	while(leftArrayIndex<leftArraySize && rightArrayIndex<rightArraySize){
		if( leftArray[leftArrayIndex]>rightArray[rightArrayIndex]){
			arr[left]=rightArray[rightArrayIndex];
			left++;
			rightArrayIndex++;
		}
		else{
			arr[left]=leftArray[leftArrayIndex];
			left++;
			leftArrayIndex++;
		}
	}
	while (leftArrayIndex<leftArraySize){
		arr[left]=leftArray[leftArrayIndex];
		left++;
		leftArrayIndex++;
	}
	while (rightArrayIndex<rightArrayIndex){
		arr[left]=rightArray[rightArrayIndex];
		left++;
		rightArrayIndex++;
	}



}
long long * input(long long int n){
	long long * arr=(long long int *)malloc(n*sizeof(n));
	for (long long int i=0;i<n;i++){
		arr[i]=rand()%n;
	}
	return arr;
} 
long long *array(long long int n,long long * arr){

	long long * a=(long long int *)malloc(n*sizeof(n));

	for (long long int i=0;i<n;i++){
		a[i]=arr[i];
	}
	return a;
}
int main(){
	FILE *ptr ;
	clock_t c1,c2,c3;
	double timeTakenBubble,timeTakenMerge;
	long long int n;
        ptr=fopen("timeData.txt","w");
	fprintf(ptr,"N\tbubblesort\tmergesort\n");
	long long * arr=input(50000);	
	for (int i=0;i<5;i++){
		long long * a1=array((i+1)*10000,arr);	
		long long * a2=array((i+1)*10000,arr);	
		c1=clock();	
		bubblesort((i+1)*10000,a1);
		c2=clock();
		mergesort(0,(i+1)*10000,a2);
		c3=clock();  
		timeTakenBubble=((double)(c2-c1))/CLOCKS_PER_SEC;
		timeTakenMerge=((double)(c3-c2))/CLOCKS_PER_SEC;
		fprintf(ptr,"%lld\t%f\t%f\n",(i+1)*10000,timeTakenBubble,timeTakenMerge);
	}
	return 0;
}
