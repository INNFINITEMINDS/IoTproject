import java.io.IOException;


public class ProxyClient {
	
	public static final int treshold_HRS_low = 60;
	public static final int treshold_HRS_high = 100;
	public static final int treshold_OxyS_low = 80;
	public static final int treshold_OxyS_high = 120;
	public static final int treshold_temp_pat_low = 35;
	public static final int treshold_temp_pat_high = 39;
	public static final int treshold_temp_room_low = 10;
	public static final int treshold_temp_room_high = 50;
	public static final int oxygen_optimal = 100;
	
	public static final int T_patient = 2000;
	public static final int T_room = 2000;
	
	public static final int Kp_oxy = 1;
	

	public static void main(String[] args) {		
		
		DiVi_ADN br = new DiVi_ADN("http://[aaaa::c30c:0:0:1]");

		// faccio la discovery e faccio partire il sistema
		br.discovery();
		
		// sarebbe utile fare un Thread a livello di ADN che "ogni tot" fa la discovery e aggiorna
		// i pazienti/stanze
		// br.start();
		
		while(true) {
        	try {
				System.in.read();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
        }

	}
	
}
