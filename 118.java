class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<>();
        for (int i = 0; i<numRows; i++) {
            List<Integer> rows = new ArrayList<>();
            rows.add(1);
            for (int j = 1; j<i; j++) {
                int sum = triangle.get(i-1).get(j-1) + triangle.get(i-1).get(j);
                rows.add(sum);
            }
            if (i > 0) rows.add(1);
            triangle.add(rows);
        }
        return triangle;   
    }
}
