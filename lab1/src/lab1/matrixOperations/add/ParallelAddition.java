package lab1.matrixOperations.add;

import lab1.Matrix;
import lab1.matrixOperations.IMatrixOperation;

/**
 * Created by Sebi on 06-Oct-17.
 */
public class ParallelAddition implements IMatrixOperation {
    @Override
    public Matrix calculate(Matrix a, Matrix b, Integer nrThreads) {
        System.out.println("Running parallel add, using " + nrThreads + " threads");

        if (a.getCols() != b.getCols() || a.getRows() != b.getRows()){
            return null;
        }

        int rows = a.getRows();
        int cols = a.getCols();
        int len = a.getCols() * a.getRows();
        double[][] res = new double[rows][cols];

        if (nrThreads < 1 || nrThreads > len){
            System.out.println("Invalid nr of threads");
            return null;
        }

        // thread operations
        int elemPerTh = len / nrThreads;
        int extraElems = len % nrThreads;
        int start = 0; int end = elemPerTh;

        Thread[] threads = new Thread[nrThreads];
        for (int i = 0; i < nrThreads; i++){
            if (i < extraElems){
                end++;
            }

            threads[i] = new Thread(new ThreadAddMat(a.getData(), b.getData(), rows, cols, res, start, end));
            threads[i].start();

            start = end;
            end += elemPerTh;
        }

        for (int i = 0; i < nrThreads; i++){
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        return new Matrix(rows, cols, res);
    }
}
