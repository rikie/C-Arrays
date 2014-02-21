/* Implementation of Merge Sort useful in many questions */
/* complexity : nlogn */

#include <stdio.h>

void merge(int *, int, int, int);
void mergesort(int *arr, int left, int right) {
	int mid = (left+right)/2;
	if(left < right) {
		mergesort(arr, left, mid);
		mergesort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}


void merge(int *arr, int left, int mid, int right) {
	int lpos = left, rpos = mid+1, pos =0;
	int i;
	int tempArr[right-left+1];
	while(lpos <= mid && rpos <= right) {
		if(arr[lpos] < arr[rpos])
			tempArr[pos++] = arr[lpos++];
		else
			tempArr[pos++] = arr[rpos++];
	}
	while(lpos <= mid) tempArr[pos++] = arr[lpos++];
	while(rpos <= right) tempArr[pos++] = arr[rpos++];

	for(i=0; i<pos; i++) {
		arr[left+i] = tempArr[i];
	}
}

int main() {
	int arr[] = {1,55,2,34,100,58,3,20};
	mergesort(arr,0,8);
	int i;
	for(i=0; i<8; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}
