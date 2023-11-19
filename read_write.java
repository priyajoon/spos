import java.util.*;
import java.util.concurrent.Semaphore;

class read_write{

	static Semaphore readlock=new Semaphore(1);
	static Semaphore writelock=new Semaphore(1);

	static int read_count=0;

	static class Read implements Runnable{
		@Override
		public void run(){
			try{
				readlock.acquire();
				read_count++;
				if(read_count==1){
					writelock.acquire();
				}
				readlock.release();

				System.out.println("thread "+Thread.currentThread().getName()+"is reading");
				Thread.sleep(1500);
				System.out.println("thread "+ Thread.currentThread().getName()+"has finished reading");

				readlock.acquire();
				read_count--;
				
				if(read_count==0){
					writelock.release();
				}
				readlock.release();

			}
			catch(InterruptedException e){
				System.out.println(e.getMessage());
			}
		}
	}

	static class Write implements Runnable{
		@Override
		public void run(){
			try{
				writelock.acquire();
				System.out.println("Thread"+Thread.currentThread().getName()+"is writing");
				Thread.sleep(2500);
				System.out.println("Thread"+Thread.currentThread().getName()+"has finished writing");
				writelock.release();
			}
			catch(InterruptedException e){
				System.out.println(e.getMessage());
			}

		}

	}

	void fun(){
		Read read=new Read();
		Write write=new Write();
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter number of process = ");
		int n=sc.nextInt();
		System.out.println("Enter 1 for reading and 0 for writing : ");
		int seq[]=new int[n];

		for(int i=0;i<n;i++){
			seq[i]=sc.nextInt();
		}

		Thread pr[]=new Thread[n];
		for(int i=0;i<n;i++){
			if(seq[i]==1){
				pr[i]=new Thread(read);
				
				pr[i].setName("Thread "+(i+1));
				
			}
			else if(seq[i]==0){
				pr[i]=new Thread(write);

				pr[i].setName("Thread "+(i+1));
				

			}
		}

		for(int i=0;i<n;i++){
			pr[i].start();
		}

		sc.close();
	}

	public static void main(String args[]){
		read_write rw=new read_write();
		rw.fun();

	}

	//  public static void main(String[] args) throws Exception {
    //     Read read = new Read();
    //     Write write = new Write();
    //     Thread t1 = new Thread(read);
    //     t1.setName("thread1");
    //     Thread t2 = new Thread(read);
    //     t2.setName("thread2");
    //     Thread t3 = new Thread(write);
    //     t3.setName("thread3");
    //     Thread t4 = new Thread(read);
    //     t4.setName("thread4");
    //     t1.start();
    //     t3.start();
    //     t2.start();
    //     t4.start();
    // }

}