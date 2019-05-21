package ce.itcr.gladiators.genetic;

import ce.itcr.gladiators.genetic.resources.Gladiator;

public class QuickSort {

	public static void quickSort(Gladiator[] arr, int start, int end){

		int partition = partition(arr, start, end);

		if(partition-1>start) {
			quickSort(arr, start, partition - 1);
		}
		if(partition+1<end) {
			quickSort(arr, partition + 1, end);
		}
	}

	public static int partition(Gladiator[] arr, int start, int end){
		Gladiator pivot = arr[end];

		for(int i=start; i<end; i++){
			if(arr[i].getFitness()<pivot.getFitness()){
				Gladiator temp= arr[start];
				arr[start]=arr[i];
				arr[i]=temp;
				start++;
			}
		}

		Gladiator temp = arr[start];
		arr[start] = pivot;
		arr[end] = temp;

		return start;
	}
}