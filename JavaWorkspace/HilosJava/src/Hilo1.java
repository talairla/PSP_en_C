public class Hilo1 extends Thread {

	public void run(){	
		System.out.println("Soy el Hilo");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("Soy el Hilo");
	}
	
}
