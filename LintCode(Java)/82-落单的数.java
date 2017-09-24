public class Solution {
    /**
      *@param A : an integer array
      *return : a integer 
      */
    public int singleNumber(int[] A) {
        // Write your code here
        int ans = 0;
    	for (int x : A) {
    		ans ^= x;
    	}
    	return ans;
    }
}