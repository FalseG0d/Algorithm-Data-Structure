package Basic;
import java.math.BigInteger;
import java.util.Scanner;
public class PlayWithBigNum {
	public void playWithInt() {
		Scanner sc=new Scanner(System.in);
		int x1=sc.nextInt();
		int x2=sc.nextInt();
		System.out.println(x1*x2);
		BigInteger one=new BigInteger("1");
		BigInteger two=(BigInteger.valueOf(23));
		System.out.println(one.add(two));
		String s=sc.next();
		BigInteger one1=new BigInteger(s,2);//changes the base of the number to 2
		String s1=sc.next();
		BigInteger one2=new BigInteger(s1,2);//changes the base of the number to 2
		System.out.println(one1.multiply(one2));
		System.out.println(one1.divide(one2));
		System.out.println(one1.subtract(one2));
		System.out.println(one1.gcd(one2));//greatest common divisor
		System.out.println(two.nextProbablePrime());
		sc.close();
	}
	public static void main(String arg[]) {
		PlayWithBigNum pwi=new PlayWithBigNum();
		pwi.playWithInt();
		System.out.println("Success");
	}

}
