package lab1.matrixOperations;

import lab1.IO.MatrixFileReader;
import lab1.IO.MatrixFileWriter;
import lab1.Matrix;

/**
 * Created by Sebi on 06-Oct-17.
 */
public class MatrixCalculator {

    /*
    Reads 2 matrixes from files
    applies the operation
    saves result in the given file
     */
    public void calculate(IMatrixOperation operation, String pathToFirst, String pathToSecond, String pathToResult, Integer nrThreads) {
        MatrixFileReader matrixFileReader = new MatrixFileReader();
        MatrixFileWriter matrixFileWriter = new MatrixFileWriter();

        Matrix a =  matrixFileReader.getFromFile(pathToFirst);
        Matrix b = matrixFileReader.getFromFile(pathToSecond);

        if (a == null || b == null){
            System.out.println("Input error");
            return;
        }

        Matrix c = operation.calculate(a, b, nrThreads);

        matrixFileWriter.saveToFile(pathToResult, c);
    }
}
