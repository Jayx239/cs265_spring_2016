
interface Cmp{
	int cmp(Object objX, Object objY);
}

public class quick_sort implements Cmp{

	public quick_sort(){
	}
		
	public int cmp(Object objX, Object objY){
		int intX = ((int) objX);
		int intY = ((int) objY);
		if(intX == intY)
			return 0;
		if(intX < intY)
			return -1;
		else
			return 1;
	}

	public void quick_sort_rel(int[] v, int left, int right){
		               int i,last;
                if(left>= right)
                        return;

                swap(v,left,right);
                last=left;
                 //partition
                 for(i=left+1; i<= right; i++)
                 if(v[i]<v[left])
                         swap(v, ++last, i);
                 //restore pivot element
                 swap(v, left, last);
                 //recursively sort each part
                 quick_sort_rel(v, left, last-1);
                 quick_sort_rel(v, last+1, right);

	}
	
	public void  quick_sort_inter(int[] v, int left, int right){
		               int i,last;
                if(cmp((Object) right,(Object) left) <=0)
                        return;

                swap(v,left,right);
                last=left;
                 //partition
                 for(i=left+1; i<= right; i++)
                 if(cmp((Object) v[i],(Object) v[left]) < 0)
                         swap(v, ++last, i);
                 //restore pivot element
                 swap(v, left, last);
                 //recursively sort each part
                 quick_sort_inter(v, left, last-1);
                 quick_sort_inter(v, last+1, right);

	}
	
	public void swap(int[] array, int ind1, int ind2){
		int temp = array[ind2];
		array[ind2] = array[ind1];
		array[ind1] = temp;
	}

	public static void main(String[] argv){
		int arraySize = Integer.parseInt(argv[0]);
		int[] randomArray = new int[arraySize];
		int[] randomArray2 = new int[arraySize];
		for(int i=0; i<arraySize; i++){
			randomArray[i] = (int)(Math.random() * arraySize);
			randomArray2[i] = randomArray[i];
		}
//		int[] randomArray2 = randomArray;

		quick_sort qs = new quick_sort();
		long startTime = System.nanoTime();
		qs.quick_sort_rel(randomArray,0,arraySize-1);
		long endTime = System.nanoTime();
		System.out.println("relational: " + (endTime-startTime)/1000000);
//		for(int i=0; i<arraySize; i++)
//			System.out.println(randomArray[i]);
		startTime = System.nanoTime();
		qs.quick_sort_inter(randomArray2,0,arraySize-1);
		endTime = System.nanoTime();
		System.out.println("inter: " + (endTime-startTime)/1000000);

//		for(int i=0; i<arraySize; i++)
//			System.out.println(randomArray2[i]);		
	}
}
