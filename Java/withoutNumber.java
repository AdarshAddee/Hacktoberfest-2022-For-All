public class withoutNumber {

    public static void main(String[] args) {
    /*
		 * Print numbers from 1 to 100 without using any numbers in your code.
		 */
		int a = 'A'/'A'; // this is equal to 1
		String s = ".........."; // length of this string is 10
		System.out.println("============ 1st Method to print numbers from 1 to 100 without using any numbers ============");
		// 1st method to print this
		for(int i=a; i<=(s.length() * s.length()); i++) {
			System.out.println(i);
		}
		
		System.out.println("============ 2nd Method to print numbers from 1 to 100 without using any numbers ============");
		// 2nd method to print this using ASCII value
		// a=97, b=98 , c=99, d=100
		for(int i=a; i<='d'; i++) {
			System.out.println(i);
		}
    }
}
