class Solution {
    List<String> str = new ArrayList<>();
    StringBuilder sb = new StringBuilder();
    String[] arr = new String[]{"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0)    //edge case
            return str;
        help(0, digits, str, arr, digits.length(), sb);
        return str;
    }
    void help(int idx, String digits, List<String> str, String[] arr, int n, StringBuilder sb){
        if(idx == n){   //base case
            str.add(sb.toString());
            return;
        }
        int val = digits.charAt(idx) - '0';
        String s = arr[val];
        for(int i = 0; i < s.length(); i++){
            sb.append(s.charAt(i));
            help(idx + 1, digits, str, arr, n, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}