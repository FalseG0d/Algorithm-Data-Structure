# Competetive Coding Mathematics

1. **Birthday Paradox**

How many people must there be in a room so that there is a 100% probability that atleast 2 people have same birthday : The answers is ofcourse 367. 

Now what wil be the same question but for probability 50% :  The answer is 23.

**Why?**

Suppose there are n people in a room, so the Probability for the for the same Birthday can be calculated as.

```
P(Same) = 1 - P(Diff)
```

```
P(Diff) = 1 * 364/365 * 363/365 * 362/365 * 361/365 *............(365 - (n - 1))/365
```

2. **Big Integer**

Very large number with digits in the order of hundreds and maybe even more cannot be stored in any primitive datatype for these we can either create an array to handle the mathematical operation or use java.math.BigInteger class.

```
import java.math.BigInteger;
import java.util.Scanner;

public class Example
{
	static BigInteger factorial(int N)
	{
		BigInteger f = new BigInteger("1"); // Or BigInteger.ONE

		for (int i = 2; i <= N; i++)
			f = f.multiply(BigInteger.valueOf(i));

		return f;
	}
	public static void main(String args[]) throws Exception
	{
		int N = 20;
		System.out.println(factorial(N));
	}
}
```

3. **Modular Arithmetic**

    1. x ≅ y mod N : This means that both x and y jave same remainder when divided by n.
    2. x ≅ y mod N : If n divides (x - y)
    3. x ≅ y mod N  and a ≅ b mod N, then (x + a) ≅ (y + b) mod N
    4. x ≅ y mod N  and a ≅ b mod N, then (x - a) ≅ (y - b) mod N


    1. (a + b) mod P = (a mod P + b mod P) mod P
    2. (a * b) mod P = (a mod P * b mod P) mod P

    3. (a / b) mod P

    This requires 3 things Modulo Inverse, Fermat's Little Principle and Binary Exponentiation

    **Modular Inverse** of an integer a mod m is an integer 'x' such that

    ```
    ax ≅ 1 mod P    or      a * a ^ -1 ≅ 1 mod P
    ```

    Every non zero integer 'a' has an inverse (modulo P) for a prime 'p' and 'a' not a multiple of 'p', example.

    ```
    1 ^ -1 mod 5 = 1
    2 ^ -1 mod 5 = 3
    3 ^ -1 mod 5 = 2
    4 ^ -1 mod 5 = 4
    5 ^ -1 mod 5 = 1
    ```

    **Fermat's Little Theoram** states that if 'p' is a prime number then for an integer 'a', the number a ^ p - a is a multiple of 'p', this is expressed as ***a ^ p ≅ a mod P*** 

    ```
    a ^ p ≅ a mod p
    a ^ p mod P = a mod p

    Multiplying both sides by a ^ -2

    a ^ (p - 2) = a ^ -1 mod p
    ```

    **Going Back To (a / b) mod P**

    (a * b ^ -1) mod P = ((a mod P) * (b ^ -1 mod P)) mod P
    (a * b ^ -1) mod P = ((a mod P) * (b ^ (P - 2) mod P)) mod P

4. **Catalan Numbers**

Sequence of natural numbers that occurs in many interesting conting problems eg. 

    1. Count the number of expressions containing n pairs of parantheses which are correctly matched.
    2. Counting the number of possible Binary Search Trees with n keys.
    3. Count the number of full binary search trees with n+1 leaves.
    4. Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.

```
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862
```

**Recursive Solution**

Cataln numbers satisfy the formula.

![Catalan Number][catalan-number]

<!--- MARKDOWN LINKS and IMAGES --->

[catalan-number]: Images/CatalanNumber.png