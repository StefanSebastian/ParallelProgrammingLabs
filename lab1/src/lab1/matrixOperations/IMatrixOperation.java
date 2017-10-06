package lab1.matrixOperations;

import lab1.Matrix;

/**
 * Created by Sebi on 06-Oct-17.
 */
public interface IMatrixOperation {
    Matrix calculate(Matrix a, Matrix b, Integer nrThreads);
}
