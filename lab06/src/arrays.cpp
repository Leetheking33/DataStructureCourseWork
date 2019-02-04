#include <climits>

int countNegatives(const int array[], int size) {
	int NegCount = 0;
	for (int i=0; i < size; i++){
		if (array[i] < 0){
			NegCount++;
		}
	}
    return NegCount;
}

int findMinOdd(const int array[], int size) {
	int smallest = INT_MAX;

	for(int i=0; i < size; i++){
		if(array[i] % 2 != 0 && array[i] < smallest){
			smallest = array[i];
		}	
	}
	if(smallest == INT_MAX){
		return -1;
	}
	return smallest;
}

int search(const int array[], int size, int value) {
	for(int i=0; i < size; i++){
		if(array[i] == value){
			return i;
		}
    	}
	return -1;
}

bool remove(int array[], int size, int index) {
	if( index >= 0 && index < size){
		for(int i= index; i < size - 1; i++){
			array[i] = array[i + 1];
		}
		return true;
	}
    return false;
}
