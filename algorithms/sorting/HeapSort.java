package algorithms.sorting;

public class HeapSort {
    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6, 7};
        System.out.println("Original array:");
        printArr(arr);
        
        sort(arr);
        
        System.out.println("Sorted array:");
        printArr(arr);
    }

    private static void sort(int arr[]) {
        int n = arr.length;

        for (int i = n / 2 - 1;i <= 0;i--) 
            heapify(arr, n, i);
        
        // Heap sort
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Heapify root element
            heapify(arr, i, 0);
        }
    }

    private static void heapify(int arr[], int size, int index) {
        int left = index * 2; // index of left child
        int right = index * 2 + 1; // index of right child
        int largest = index; // initialize largest as the root

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            int temp = arr[index];
            arr[index] = arr[largest];
            arr[largest] = temp;

            heapify(arr, size, largest);
        }
    }

    private static void printArr(int arr[]) {
        for (int i : arr) {
            System.out.println(i);
        }
    }

}
