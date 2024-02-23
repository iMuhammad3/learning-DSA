package algorithms.searching;

public class BinarySearch {

    public static void main(String[] args) {
        int array[] = { 1, 2, 40, 5, 6, 700 };
        int value = 5;
        int res = binarySearch(array, value);
        if (res == -1) {
            System.out.println("Item was not found in array");
        } else {
            System.out.println("Item was found at index " + res);
        }
    }

    // Wrapper function to call recursive binary search
    private static int binarySearch(int array[], int value) {
        return search(array, value, 0, array.length - 1);
    }

    // Recursive binary search function
    private static int search(int array[], int value, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;

            if (array[mid] == value) {
                return mid;
            }
            // If the value is smaller, search in the left half
            else if (array[mid] > value) {
                return search(array, value, left, mid - 1);
            }
            // If the value is greater, search in the right half
            else {
                return search(array, value, mid + 1, right);
            }
        }
        // If the target is not present in the array
        return -1;
    }
}