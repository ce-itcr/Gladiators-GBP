package ce.itcr.gladiators.genetic;

import ce.itcr.gladiators.genetic.resources.Gladiator;

import java.util.Arrays;

public class QuickSort {

	public static void main(String[] args) {
//		int[] arr = {4, 5, 1, 2, 3, 3};
//		quickSort(arr, 0, arr.length-1);
//		System.out.println(Arrays.toString(arr));
	}

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
//			System.out.println("arr[i]" + arr[i]);
//			System.out.println(arr[i].getFitness());
//			System.out.println("arr[end]" + arr[end]);
//			System.out.println(arr[end].getFitness());
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