public class AbrirCalculadora{
	public static void main(String[] args){
		Runtime entorno = Runtime.getRuntime();
		String comando = "gnome-calculator";
		Process p;
		try{
			p = entorno.exec( comando );
		 }catch (Exception e){
			System.out.println("Error en el comando: "+comando);
			e.printStackTrace();
		}
	}
}