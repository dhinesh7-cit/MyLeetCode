class 2570 {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int[] sum = new int[1001];

        for (int[] pair : nums1) sum[pair[0]] += pair[1];
        for (int[] pair : nums2) sum[pair[0]] += pair[1];

        int count = 0;
        for (int i = 1; i <= 1000; i++) {
            if (sum[i] > 0) count++;
        }

        int[][] result = new int[count][2];
        int index = 0;
        for (int i = 1; i <= 1000; i++) {
            if (sum[i] > 0) {
                result[index][0] = i;
                result[index][1] = sum[i];
                index++;
            }
        }

        return result;
    }
}
