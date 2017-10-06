package lab1.matrixOperations;

import lab1.Matrix;

/**
 * Created by Sebi on 06-Oct-17.
 */
public class SerialAddition implements IMatrixOperation {
    public Matrix calculate(Matrix a, Matrix b, Integer nrThreads){
        if (a.getCols() != b.getCols() || a.getRows() != b.getRows()){
            return null;
        }

        int rows = a.getRows();
        int cols = a.getCols();
        double[][] res = new double[rows][cols];
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                res[i][j] = a.getData()[i][j] + b.getData()[i][j];
            }
        }
        return new Matrix(rows, cols, res);
    }
}
