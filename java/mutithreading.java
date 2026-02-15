public class ThreadSleepExample implements Runnable {

    @Override
    public void run() {
        String threadName = Thread.currentThread().getName(); // Get the name of the current thread
        System.out.println(threadName + " is starting.");
        
        try {
            // Pause the execution of the current thread for 500 milliseconds
            Thread.sleep(500); 
        } catch (InterruptedException e) {
            // Handle the exception if the thread is interrupted during sleep
            System.out.println(threadName + " was interrupted.");
            e.printStackTrace();
        }
        
        System.out.println(threadName + " has finished execution.");
    }

    public static void main(String[] args) {
        System.out.println("Main thread started. Creating child threads...");

        // Create four instances of our Runnable class
        ThreadSleepExample myRunnable = new ThreadSleepExample();

        // Create four Thread objects and name them
        Thread thread1 = new Thread(myRunnable, "Thread-1");
        Thread thread2 = new Thread(myRunnable, "Thread-2");
        Thread thread3 = new Thread(myRunnable, "Thread-3");
        Thread thread4 = new Thread(myRunnable, "Thread-4");

        // Start the threads
        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();
        
        System.out.println("All child threads started. Main thread finishing.");
    }
}
