package algorithms.sorting;

public class BubbleSort {
    public static void main(String[] args) {
        int array[] = { 12, 345, 2, 3, 12, 5, 65, 111, 54, 24, 234, 2, 345, 11, 98 };
        sort(array);
        for (int i : array) System.out.println(i);
    }

    private static void sort(int[] array) {
        int i, j;
        for (i = 0; i < array.length; i++)
            for (j = i + 1; j < array.length; j++)
                if (array[i] > array[j])
                    swap(array, i, j);
    }

    private static void swap(int array[], int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
