package tests;

import matrix.Matrix;
import matrix.MatrixException;
import matrix.operations.operators.Multiplication;
import matrix.operations.ParallelCalculator;
import matrix.operations.SerialCalculator;
import matrix.types.IntElem;
import matrix.types.MatrixElement;
import matrix.utils.MatrixUtils;
import org.junit.Test;

import static org.junit.Assert.assertTrue;

/**
 * Created by Sebi on 21-Oct-17.
 */
public class MultiplyTest {
    @Test
    public void multiplyInt1() throws MatrixException {
        IntElem n1 = new IntElem(1);
        IntElem n2 = new IntElem(2);
        IntElem n3 = new IntElem(4);
        IntElem n4 = new IntElem(5);
        MatrixElement[][] data = {{n1, n2}, {n3, n4}};
        IntElem n5 = new IntElem(1);
        IntElem n6 = new IntElem(2);
        IntElem n7 = new IntElem(4);
        IntElem n8 = new IntElem(5);
        MatrixElement[][] data2 = {{n5, n6}, {n7, n8}};
        Matrix m1 = new Matrix(2, 2);
        Matrix m2 = new Matrix(2, 2);
        m1.setData(data);
        m2.setData(data2);

        Matrix m3 = new Matrix(2,2);
        Matrix m4 = new Matrix(2, 2);
        ParallelCalculator parallelCalculator = new ParallelCalculator();
        SerialCalculator serialCalculator = new SerialCalculator();

        parallelCalculator.calculate(m1, m2, m3, 2, new Multiplication());
        serialCalculator.calculate(m1, m2, m4, new Multiplication());

        assertTrue(m3.equals(m4));
    }

    private void runSimulationInt(int nrThr, int nrRows1, int nrCols1, int nrRows2, int nrCols2) throws MatrixException {
        System.out.println("Int multiplication with " + nrThr + " threads");
        System.out.println("Matrix dimensions " + nrRows1 + "x" + nrCols1 + " -- " + nrRows2 + "x" + nrCols2);
        Matrix m1 = MatrixUtils.generateIntMatrix(nrRows1, nrCols1);
        Matrix m2 = MatrixUtils.generateIntMatrix(nrRows2, nrCols2);
        Matrix m3 = new Matrix(nrRows1, nrCols2);
        Matrix m4 = new Matrix(nrRows1, nrCols2);
        ParallelCalculator parallelCalculator = new ParallelCalculator();
        SerialCalculator serialCalculator = new SerialCalculator();


        parallelCalculator.calculate(m1, m2, m3, nrThr, new Multiplication());
        serialCalculator.calculate(m1, m2, m4, new Multiplication());

        assertTrue(m3.equals(m4));
    }

    @Test
    public void runSimulationIntCaller() throws MatrixException {
        for (int i = 2; i <= 8; i += 2){
            runSimulationInt(i, 1000, 1000, 1000, 1000);
            System.out.println("---------------------------");
        }
    }

    private void runSimulationDouble(int nrThr, int nrRows1, int nrCols1, int nrRows2, int nrCols2) throws MatrixException {
        System.out.println("double multiplication with " + nrThr + " threads");
        System.out.println("Matrix dimensions " + nrRows1 + "x" + nrCols1 + " -- " + nrRows2 + "x" + nrCols2);
        Matrix m1 = MatrixUtils.generateDoubleMatrix(nrRows1, nrCols1);
        Matrix m2 = MatrixUtils.generateDoubleMatrix(nrRows2, nrCols2);
        Matrix m3 = new Matrix(nrRows1, nrCols2);
        Matrix m4 = new Matrix(nrRows1, nrCols2);
        ParallelCalculator parallelCalculator = new ParallelCalculator();
        SerialCalculator serialCalculator = new SerialCalculator();


        parallelCalculator.calculate(m1, m2, m3, nrThr, new Multiplication());
        serialCalculator.calculate(m1, m2, m4, new Multiplication());

        assertTrue(m3.equals(m4));
    }

    @Test
    public void runSimulationDoubleCaller() throws MatrixException {
        for (int i = 2; i <= 8; i += 2){
            runSimulationDouble(i, 1000, 1000, 1000, 1000);
            System.out.println("---------------------------");
        }
    }

    private void runSimulationComplex(int nrThr, int nrRows1, int nrCols1, int nrRows2, int nrCols2) throws MatrixException {
        System.out.println("Complex multiplication with " + nrThr + " threads");
        System.out.println("Matrix dimensions " + nrRows1 + "x" + nrCols1 + " -- " + nrRows2 + "x" + nrCols2);

        Matrix m1 = MatrixUtils.generateComplexMatrix(nrRows1, nrCols1);
        Matrix m2 = MatrixUtils.generateComplexMatrix(nrRows2, nrCols2);
        Matrix m3 = new Matrix(nrRows1, nrCols2);
        Matrix m4 = new Matrix(nrRows1, nrCols2);
        ParallelCalculator parallelCalculator = new ParallelCalculator();
        SerialCalculator serialCalculator = new SerialCalculator();


        parallelCalculator.calculate(m1, m2, m3, nrThr, new Multiplication());
        serialCalculator.calculate(m1, m2, m4, new Multiplication());

        assertTrue(m3.equals(m4));
    }

    @Test
    public void runSimulationComplexCaller() throws MatrixException {
        for (int i = 2; i <= 8; i += 2){
            runSimulationComplex(i, 1000, 1000, 1000, 1000);
            System.out.println("---------------------------------");
        }
    }
}
