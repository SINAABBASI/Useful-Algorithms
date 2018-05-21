import java.util.Scanner;
import java.math.BigInteger;
public class main{
	public static void main(String[] args){
		BigInteger[][] dp = new BigInteger [100011][2];
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(),k = sc.nextInt();
		k--;
		dp[1][0] = BigInteger.ZERO;
		dp[1][1] = BigInteger.ZERO;
		BigInteger BK = BigInteger.valueOf(k);
		dp[1][1] = dp[1][1].add(BK);
		
		for(int i = 2; i <= n ;i++){
			dp[i][0] = BigInteger.ZERO;
			dp[i][1] = BigInteger.ZERO;
			
			dp[i][0] = dp[i][0].add(dp[i-1][1]);
			
			BigInteger temp = BigInteger.ZERO;
			temp = temp.add(dp[i-1][0]);
			temp = temp.add(dp[i-1][1]);
			dp[i][1] = dp[i][1].add(temp.multiply(BK)) ;
		}
		BigInteger ans = BigInteger.ZERO;
		ans = ans.add(dp[n][1]);
		ans = ans.add(dp[n][0]);
		System.out.println(ans);
	}
}