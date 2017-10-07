package lab1;

import lab1.matrixOperations.MatrixCalculator;
import lab1.matrixOperations.multiply.ParallelMultiply;
import lab1.matrixOperations.multiply.SerialMultiply;
import lab1.utils.MatrixCalculatorException;
import lab1.utils.MatrixFileComparer;
import lab1.utils.MatrixFileWriter;
import lab1.utils.MatrixGenerator;

/**
 * Created by Sebi on 06-Oct-17.
 */
public class Main {
    private static String filePrefix = "E:/Info/anu3/progr paralela/labs/ParallelProgrammingLabs/lab1/src/lab1/data/";

    public static void runSimulation(){
        MatrixFileWriter matrixFileWriter = new MatrixFileWriter();
        MatrixCalculator matrixCalculator = new MatrixCalculator();
        MatrixFileComparer matrixFileComparer = new MatrixFileComparer();
        MatrixGenerator matrixGenerator = new MatrixGenerator();


        matrixFileWriter.saveToFile(filePrefix + "mat1.txt", matrixGenerator.getMatrix(2000, 2000));
        matrixFileWriter.saveToFile(filePrefix + "mat2.txt", matrixGenerator.getMatrix(2000, 2000));
        try {
            matrixCalculator.calculate(new SerialMultiply(), filePrefix + "mat1.txt", filePrefix + "mat2.txt", filePrefix + "res1.txt", 0);
            matrixCalculator.calculate(new ParallelMultiply(), filePrefix + "mat1.txt", filePrefix + "mat2.txt", filePrefix + "res2.txt", 4);

            boolean valid = matrixFileComparer.compare(filePrefix + "res1.txt", filePrefix + "res2.txt");
            if (valid) {
                System.out.println("Result is valid");
            } else {
                System.out.println("Result is not valid");
            }
        } catch (MatrixCalculatorException e){
            System.out.println(e.getMessage());
        }
    }


    public static void main(String[] args) {
        runSimulation();
    }
}
