
public class EjecutarHilos {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// Creamos hilos que son subclase de Thread y los ejecutamos
		Hilo1 h1 = new Hilo1();
		Hilo2 h2 = new Hilo2();
		
		h1.start();
		h2.start();
		
		//Lanzar un hilo que implementa runnable
		Hilo3 h3 = new Hilo3();
		Thread t3 = new Thread(h3);
		t3.start();
		System.out.println(h1.toString()+"ID: "+h1.getId());
		h1.interrupt();
		
		System.out.println("Fuera del hilo");
	}

}
