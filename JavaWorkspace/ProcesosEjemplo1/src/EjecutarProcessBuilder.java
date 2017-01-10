import java.io.IOException;
import java.util.Map;


public class EjecutarProcessBuilder {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] comando={"mate-terminal","-e","ping 8.8.8.8"};
		
		
		ProcessBuilder pb = new ProcessBuilder(comando);
		Map variables_entorno = pb.environment();
		System.out.println("Variables de entorno:");
		System.out.println(variables_entorno);
		
		try {
			pb.start();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
