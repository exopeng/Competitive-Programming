import java.util.*;
public class wasp {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		StringTokenizer st = new StringTokenizer(s.nextLine());
		int V = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(s.nextLine());
		int curDamage = 0;
		for(int i=0; i<N; i++){
			curDamage += Integer.parseInt(st.nextToken());
			if(curDamage*(i+1) >= V){
				System.out.println(i);
				break;
			}
		}
	}
}