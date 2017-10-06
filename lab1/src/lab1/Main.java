package lab1;

import lab1.matrixOperations.MatrixCalculator;
import lab1.matrixOperations.parallelAdd.ParallelAddition;

/**
 * Created by Sebi on 06-Oct-17.
 */
public class Main {
    private static String filePrefix = "E:/Info/anu3/progr paralela/lab1/src/lab1/data/";

    public static void main(String[] args) {
        /*MatrixFileWriter fileGenerator = new MatrixFileWriter();
        fileGenerator.generateToFile(filePrefix + "mat1.txt", 4, 4);
        fileGenerator.generateToFile(filePrefix + "mat2.txt", 4, 4);*/
        MatrixCalculator matrixCalculator = new MatrixCalculator();
        matrixCalculator.calculate(new ParallelAddition(), filePrefix + "mat1.txt", filePrefix + "mat2.txt", filePrefix + "res3.txt", 3);

    }
}
