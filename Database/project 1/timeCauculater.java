
public class timeCauculater {

    long startTime = System.currentTimeMillis();
    long lastTime = System.currentTimeMillis();

    public timeCauculater () {
        startTime = System.currentTimeMillis();
    }

    public void printTime(int type) {
        long endTime = System.currentTimeMillis();
        long timeElapsed = endTime - lastTime;
        long timeElapsedTotal = endTime - startTime;
        switch (type){
            case 1:
            System.out.println("Time to initialize database: " + timeElapsed + " milliseconds");
            break;
            case 2:
            System.out.println("Time to search: " + timeElapsed + " milliseconds");
            break;
        }
        
        System.out.println("Execution time in milliseconds: " + timeElapsedTotal);
        lastTime = endTime;
    }
}
