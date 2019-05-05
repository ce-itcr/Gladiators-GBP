package ce.itcr.gladiators.genetic;

import ce.itcr.gladiators.genetic.resources.Gladiator;

public class QuickSort {
	
	public void quickSort(Gladiator arr[], int begin, int end) {
	    if (begin < end) {
	        int partitionIndex = partition(arr, begin, end);
	 
	        quickSort(arr, begin, partitionIndex-1);
	        quickSort(arr, partitionIndex+1, end);
	    }
	}
	
	private int partition(Gladiator arr[], int begin, int end) {
	    int pivot = arr[end].getFitness();
	    int i = (begin-1);
	 
	    for (int j = begin; j < end; j++) {
	        if (arr[j].getFitness() <= pivot) {
	            i++;
	 
	            Gladiator swapTemp = arr[i];
	            arr[i] = arr[j];
	            arr[j] = swapTemp;
	        }
	    }
	 
	    Gladiator swapTemp = arr[i+1];
	    arr[i+1] = arr[end];
	    arr[end] = swapTemp;
	 
	    return i+1;
	}

}
