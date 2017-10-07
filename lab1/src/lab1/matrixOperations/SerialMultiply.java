package lab1.matrixOperations;

import lab1.Matrix;

/**
 * Created by Sebi on 07-Oct-17.
 */
public class SerialMultiply implements IMatrixOperation {

    /*
    dot product between row identified with idx1 in matrix a
     and column identified with idx2 in matrix b
     */
    private double dotProduct(Matrix a, Matrix b, int idx1, int idx2){
        double prod = 0;
        for (int i = 0; i < a.getCols(); i++){
            prod += a.getData()[idx1][i] * b.getData()[i][idx2];
        }
        return prod;
    }

    @Override
    public Matrix calculate(Matrix a, Matrix b, Integer nrThreads) {
        if (a.getCols() != b.getRows()){
            System.out.println("Invalid matrixes");
            return null;
        }

        int rows = a.getRows();
        int cols = b.getCols();
        double[][] res = new double[rows][cols];

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                res[i][j] = dotProduct(a, b, i, j);
            }
        }

        return new Matrix(rows, cols, res);
    }
}
