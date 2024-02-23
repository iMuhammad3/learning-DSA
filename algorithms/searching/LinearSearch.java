package algorithms.searching;

class LinearSearch {
    public static void main(String[] args) {
        int array[] = {1, 2, 40, 50, 600, 700};
        int value = 3;
        int res = search(array, value);
        if(res == -1) {
            System.out.println("Item was not found in array");
        } else {
            System.out.println("Item was found at index " + res);
        }
    }

    static int search(int array[], int value) {
        for (int i = 0;i < array.length;i++) {
            if (array[i] == value) 
                return i + 1;
        }
        return -1;
    }
}