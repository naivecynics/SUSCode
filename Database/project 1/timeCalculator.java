
public class timeCalculator {

    long startTime = System.currentTimeMillis();
    long lastTime = System.currentTimeMillis();

    public timeCalculator () {
        startTime = System.currentTimeMillis();
    }

    public void resetTime() {
        lastTime = System.currentTimeMillis();
    }

    public void printTime() {
        long endTime = System.currentTimeMillis();
        long timeElapsed = endTime - lastTime;
        //long timeElapsedTotal = endTime - startTime;

        System.out.println("Execution time for last operation: " + timeElapsed);
        //System.out.println("Execution time in total: " + timeElapsedTotal);
        lastTime = endTime;
    }
}
