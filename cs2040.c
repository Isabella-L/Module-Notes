/****** bubble sort*****/
void bubble_sort(){
	for (j=0; j<n-1; j++)
		for(i=0; i<n-j-1; i++)
			if(A[i]>A[i+1])
				swap(A[i], A[i+1]);
}


/****** insertion sort*****/
void insertion_sort(){
	for(i=1; i<n; i++){
		e = A[i]; j=i;
		while(j>0){
			if(A[j-1]>e) A[j]=A[j-1];
			else break;
		}
	}
}


/****** selection sort*****/
void selection_sort(){
	int i, j, min_idx;

	for(i=0; i<n-1; i++){
		min_idx = i;
		for(j=i+1; j<n; j++){
			if(arr[j]<arr[min_idx]) min_idx=j;
		}
		swap(&arr[min_idx], &arr[i]);
	}
}

/****** merge sort*****/
void merge(){
	int N = high-low+1;
	int b[n];
	int left=low, right=mid+1, bIdx=0;

	while(left<=mid && right<=high) //merging
		b[bIdx++] = (a[left]<=a[right]) ? a[left++]:a[right++]; 
	while(left<=mid) b[bIdx++] = a[left++];
	while(right<=high) b[bIdx++] = a[right++];

	for(int k=0; k<N; k++) a[low+k]=b[k];
}

void merge_sort(){
	if(low<high) {
		int mid=(low+high)/2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge_sort(a, low, mid, high);

	}
}


/****** quick sort*****/
int partition(int arr[], int i, int j) {
	int p=arr[i];
	int m=i;
	for(int k=i+1; k<=j; k++){
		if(arr[k]<p){
			m++;
			swap(a[k], a[m]);
		}
	}
	swap(a[i], a[m]);

	return m;
}

void quick_sort(int arr[], int low, int high){
	if(low<high){
		int pivotIdx = partition(a, low, high); //O(N)
		quick_sort(a, low, pivotIdx-1); //recursively sort left subarr
		quick_sort(a, pivotIdx+1, high);//then sort right subarr
	}
}

/***random quick sort*****/
int partition(int arr[], int i, int j) {
	int p=arr[i];
	int m=i;
	for(int k=i+1; k<=j; k++){
		if(arr[k]<p){
			m++;
			swap(a[k], a[m]);
		}
	}
	swap(a[i], a[m]);

	return m;
}

int random_pivoting(int arr[], int i, int j) {
	srand(time(NULL));
	int random = i + rand()%(j-i);

	swap(a[random], a[j]);

	return partition(arr, i, j);
}

void quick_sort(int arr[], int low, int high){
	if(low<high){
		int pivotIdx = random_pivoting(a, low, high); //O(N)
		quick_sort(a, low, pivotIdx-1); //recursively sort left subarr
		quick_sort(a, pivotIdx+1, high);//then sort right subarr
	}
}

