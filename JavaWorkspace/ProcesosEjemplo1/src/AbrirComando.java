
public class AbrirComando {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Runtime entorno = Runtime.getRuntime();
		if(args.length != 1){
			System.out.println("Error!, el número de parámetros es incorrecto");
		}else{
			Process p;
			try{
				p = entorno.exec("mate-terminal");
			}catch(Exception e){
				System.err.println("Algo ha ido mal...");
				e.printStackTrace();
			}
		}
	}

}
