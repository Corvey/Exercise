import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Map;

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
    	Hashtable<Integer, Integer> ht1 = numsToHashTable(nums1);
    	Hashtable<Integer, Integer> ht2 = numsToHashTable(nums2);
    	ArrayList<Integer> list = new ArrayList<>();
    	Integer key, val1, val2, val;
    	for (Map.Entry<Integer, Integer> entry : ht2.entrySet()) {
    		key = entry.getKey();
    		val2 = entry.getValue();
    		val1 = ht1.get(key);
    		if (val1 != null) {
    			val = Math.min(val1, val2);
    			for (int i=0; i<val; ++i) {
    				list.add(key);
    			}
    		}
    	}
    	int[] ans = new int[list.size()];
    	for (int i=0; i<ans.length; ++i) {
    		ans[i] = list.get(i);
    	}
    	list.clear();
    	ht1.clear();
    	ht2.clear();
    	return ans;
    }
    private Hashtable<Integer, Integer> numsToHashTable(int[] nums) {
    	Hashtable<Integer, Integer> ht = new Hashtable<>();
    	Integer cnt;
    	for (int x : nums) {
    		cnt = ht.get(x);
    		if (cnt == null) {
    			ht.put(x, 1);
    		} else {
    			ht.put(x, cnt+1);
    		}
    	}
    	return ht;
    }
}