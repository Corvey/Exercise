public class Solution {
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    public int[] intersection(int[] nums1, int[] nums2) {
        // Write your code here
    	if (nums2.length < nums1.length) {
    		return intersection(nums2, nums1);
    	}
    	Hashtable<Integer, Boolean> hashtable = new Hashtable<>();
    	for (int x : nums1) {
    		hashtable.put(x, false);
    	}
    	ArrayList<Integer> list = new ArrayList<>();
    	for (int x : nums2) {
    		Boolean isExist = hashtable.get(x);
    		if (isExist != null && isExist == false) {
    			list.add(x);
    			hashtable.put(x, true);
    		}
    	}
    	hashtable.clear();
    	int[] ans = new int[list.size()];
    	for (int i=0; i<ans.length; ++i) {
    		ans[i] = list.get(i);
    	}
    	list.clear();
    	return ans;
    }
}