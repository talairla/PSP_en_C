import java.io.IOException;


public class EjecutarProcesos {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Runtime entorno = Runtime.getRuntime();
		Process p1, p2;
		
		try {
			p1 = entorno.exec("java Proceso1");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			p2 = entorno.exec("java Proceso2");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
