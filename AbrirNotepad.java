public class AbrirNotepad{
	public static void main(String[] args){
		Runtime entorno = Runtime.getRuntime();
		String comando = "notepad";
		Process p;
		try{
			p = entorno.exec( comando );
		 }catch (Exception e){
			System.out.println("Error en el comando: "+comando);
			e.printStackTrace();
		}
	}
}