import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Arrays;
import java.util.HashSet;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

/**
 * Spoj Problem: ACPC11B
 Merge and Sort the array
 * @author madhurbhargava
 *
 */
public class ACPC11B {
	
	public static void main(String[] args) throws Exception
	{
		
		{
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			PrintWriter out = new PrintWriter(System.out);
			int numTestCases = Integer.parseInt(reader.readLine());
			for(int i = 0; i < numTestCases; i++)
			{
				int[] arr1 = convertToUniqueIntArr(reader.readLine());
				int[] arr2 = convertToUniqueIntArr(reader.readLine());
				//int[] array1and2 = new int[array1.length + array2.length];
				//System.arraycopy(array1, 0, array1and2, 0, array1.length);
				//System.arraycopy(array2, 0, array1and2, array1.length, array2.length);
				//Arrays.sort(array1and2);
				//int min = minDiff(array1and2);
				int min = minDiff(arr1, arr2);
				out.println(min);
				out.flush();
			
			}
		}
	}
	
	/*private static int minDiff(int[]arr)
	{
		int diff = arr[0];
		for(int i = 0; i < arr.length - 1; i++)
		{
			int temp = arr[i+1]-arr[i];
			if(temp < diff)
			{
				diff = temp;
			}
		}
		return diff;
	}*/
	
	private static int minDiff(int[]arr1, int arr2[])
	{
		int diff = Math.max(arr1[arr1.length - 1], arr2[arr2.length - 1]);
		for(int i = 0; i < arr1.length; i++)
		{
			for(int j = 0; j < arr2.length; j++)
			{
				int temp = arr2[j] - arr1[i];
				if(temp < 0)
				{
					temp = temp*-1;
				}
				if(temp < diff)
				{
					diff = temp;
				}
			}
		}
		return diff;
	}
	
	private static int[] convertToUniqueIntArr(String data)
	{
		StringTokenizer tokens = new StringTokenizer(data);
		boolean start = true;
		HashSet<Integer> set = null;
		while(tokens.hasMoreTokens())
		{
			if(start)
			{
				set = new HashSet<Integer>();
				start = false;
				tokens.nextToken();//skip the first element
			}
			else
			{
				set.add(Integer.parseInt((tokens.nextToken())));
			}
		}
		
		int arr[] = new int[set.size()];
		int i = 0;
		for(Integer element:set)
		{
			arr[i++] = element;
		}
		return arr;
	}
}
