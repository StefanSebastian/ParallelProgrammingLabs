package lab1.matrixOperations.add;

/**
 * Created by Sebi on 06-Oct-17.
 */
public class ThreadAddMat implements Runnable {
    
    private double[][] a;
    private double[][] b;
    private int rows;
    private int cols;
    private double[][] res;
    private int start;
    private int end;

    public ThreadAddMat(double[][] a, double[][] b, int rows, int cols, double[][] res, int start, int end) {
        this.a = a;
        this.b = b;
        this.rows = rows;
        this.cols = cols;
        this.res = res;
        this.start = start;
        this.end = end;
    }

    @Override
    public void run() {

        int startRow = start / cols;
        int startCol = start % cols;

        int endRow = end / cols;
        int endCol = end % cols;

        System.out.println("Start row: " + startRow + " start col : " + startCol + " end row " + endRow + " endcol " + endCol);

        int i = startRow; int j = startCol;
        while (!(i == endRow && j == endCol)){
            res[i][j] = a[i][j] + b[i][j];
            if (j < cols - 1){
                j++;
            } else {
                j = 0;
                i++;
            }
        }

    }
}
