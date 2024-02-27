package algorithms.sorting;

public class SelectionSort {
    public static void main(String[] args) {
        int[] array = { 12, 1, 45, 30, 2, 3, 100, 101, 91 };

        sort(array);

        for (Integer i : array)
            System.out.println(i);
    }

    private static void sort(int[] array) {

        int n = array.length;

        for (int i = 0; i < n - 1; i++) {

            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }

            swap(array, i, minIndex);
        }

    }

    private static void swap(int array[], int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
