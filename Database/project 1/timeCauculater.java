
public class timeCauculater {

    long startTime = System.currentTimeMillis();
    long lastTime = System.currentTimeMillis();

    public timeCauculater () {
        startTime = System.currentTimeMillis();
    }

    public void printTime(int type) {
        long endTime = System.currentTimeMillis();
        long lastTime = endTime;
        long timeElapsed = endTime - startTime;

        if (type == 1) { //intialize database
            System.out.println("Time to initialize database: " + (lastTime - startTime) + " milliseconds");  
        }
        
        System.out.println("Execution time in milliseconds: " + timeElapsed);
    }
}
