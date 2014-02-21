/* Find two elements in an array whose sum is closest to zero */

#include <stdio.h>
#include <math.h>
#include <limits.h>

void merge(int *, int, int, int);
void mergeSort(int *arr, int left, int right) {
	int mid = (left +right)/2;
	if(left < right) {
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}

void merge(int *arr, int left, int mid, int right) {
	int lpos = left, rpos = mid +1, pos =0, i;
	int tempArr[right-left+1];
	while(lpos <= mid && rpos <= right) {
		if(arr[lpos] < arr[rpos]) {
			tempArr[pos++] = arr[lpos++];
		}
		else {
			tempArr[pos++] = arr[rpos++];
		}
	}
	while(lpos <= mid) tempArr[pos++] = arr[lpos++];
	while(rpos <= right) tempArr[pos++] = arr[rpos++];

	for(i=0; i<pos; i++) {
		arr[left+i] = tempArr[i];
	}
}

void minAbsSumPair(int arr[], int size) {
	int sum, min_sum = INT_MAX;
	int l =0, r = size-1;
	int min_l = l, min_r = r;
	if(size < 2) {
		printf("Invalid Input\n");
	}
	mergeSort(arr, l, size);
	while(l < r) {
		sum = arr[l] + arr[r];
		if(abs(sum) > abs(min_sum)) {
			min_sum = sum;
			min_l = l;
			min_r = r;
		}
		if(sum < 0) l++;
		else if(sum > 0) r--;
		else break;
	}
	printf("The two elements which give the minimum sum in the arry are %d and %d\n", arr[min_l], arr[min_r]);
	return;
}

int main() {
	int arr[] = {1, 80, 60, -10, 70, -80, 85};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i;
	minAbsSumPair(arr, n);
	return 0;
}
