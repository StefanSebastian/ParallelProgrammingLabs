package matrix;

import matrix.operations.operators.Addition;
import matrix.operations.operators.Multiplication;
import matrix.operations.ParallelCalculator;
import matrix.operations.SerialCalculator;
import matrix.utils.MatrixUtils;

import java.io.IOException;
import java.net.URISyntaxException;
import java.util.Scanner;

/**
 * Created by Sebi on 21-Oct-17.
 */
public class RunSimulation {

    public static void operationRun(int op, int r1, int c1, int r2, int c2, int nrTh, Matrix m1, Matrix m2) throws MatrixException, IOException, URISyntaxException {
        SerialCalculator serialCalculator = new SerialCalculator();
        ParallelCalculator parallelCalculator = new ParallelCalculator();

        if (op == 1){
            Matrix m3 = new Matrix(r1, c1);
            Matrix m4 = new Matrix(r2, c2);

            System.out.println("Running serial operations");
            serialCalculator.calculate(m1, m2, m3, new Addition());
            System.out.println("Running parallel operations");
            parallelCalculator.calculate(m1, m2, m4, nrTh, new Addition());

            if (m3.equals(m4)){
                System.out.println("Valid result");
            } else {
                System.out.println("Invalid result");
            }

            System.out.println("Saving results");
            MatrixUtils.writeMatrix("E:\\Info\\anu3\\progr paralela\\labs\\ParallelProgrammingLabs\\lab2\\Lab2Java\\src\\matrix\\files\\ser.txt", m3);
            MatrixUtils.writeMatrix("E:\\Info\\anu3\\progr paralela\\labs\\ParallelProgrammingLabs\\lab2\\Lab2Java\\src\\matrix\\files\\par.txt", m4);


        } else {
            Matrix m3 = new Matrix(r1, c2);
            Matrix m4 = new Matrix(r1, c2);

            System.out.println("Running serial operations");
            serialCalculator.calculate(m1, m2, m3, new Multiplication());
            System.out.println("Running parallel operations");
            parallelCalculator.calculate(m1, m2, m4, nrTh, new Multiplication());

            if (m3.equals(m4)){
                System.out.println("Valid result");
            } else {
                System.out.println("Invalid result");
            }

            System.out.println("Saving results");
            MatrixUtils.writeMatrix("E:\\Info\\anu3\\progr paralela\\labs\\ParallelProgrammingLabs\\lab2\\Lab2Java\\src\\matrix\\files\\ser.txt", m3);
            MatrixUtils.writeMatrix("E:\\Info\\anu3\\progr paralela\\labs\\ParallelProgrammingLabs\\lab2\\Lab2Java\\src\\matrix\\files\\par.txt", m4);

        }
    }

    public static void intSim(int r1, int c1, int r2, int c2, int nrTh, int op) throws MatrixException, IOException, URISyntaxException {
        Matrix m1;
        Matrix m2;
        System.out.println("Generating first matrix");
        m1 = MatrixUtils.generateIntMatrix(r1, c1);
        MatrixUtils.writeMatrix("E:\\Info\\anu3\\progr paralela\\labs\\ParallelProgrammingLabs\\lab2\\Lab2Java\\src\\matrix\\files\\mat1.txt", m1);

        System.out.println("Generating second matrix");
        m2 = MatrixUtils.generateIntMatrix(r2, c2);
        MatrixUtils.writeMatrix("E:\\Info\\anu3\\progr paralela\\labs\\ParallelProgrammingLabs\\lab2\\Lab2Java\\src\\matrix\\files\\mat2.txt", m2);
        operationRun(op, r1, c1, r2, c2, nrTh, m1, m2);
    }

    public static void complexSim(int r1, int c1, int r2, int c2, int nrTh, int op) throws IOException, URISyntaxException, MatrixException {
        Matrix m1;
        Matrix m2;
        System.out.println("Generating first matrix");
        m1 = MatrixUtils.generateComplexMatrix(r1, c1);
        MatrixUtils.writeMatrix("E:\\Info\\anu3\\progr paralela\\labs\\ParallelProgrammingLabs\\lab2\\Lab2Java\\src\\matrix\\files\\mat1.txt", m1);

        System.out.println("Generating second matrix");
        m2 = MatrixUtils.generateComplexMatrix(r2, c2);
        MatrixUtils.writeMatrix("E:\\Info\\anu3\\progr paralela\\labs\\ParallelProgrammingLabs\\lab2\\Lab2Java\\src\\matrix\\files\\mat2.txt", m2);
        operationRun(op, r1, c1, r2, c2, nrTh, m1, m2);
    }

    public static void runSimulation() throws MatrixException, IOException, URISyntaxException {
        Scanner scanner = new Scanner(System.in);

        System.out.println("First matrix dimensions: ");
        int r1 = scanner.nextInt();
        int c1 = scanner.nextInt();

        System.out.println("Second matrix dimensions: ");
        int r2 = scanner.nextInt();
        int c2 = scanner.nextInt();

        System.out.println("Operation 1.add 2.multiply");
        int operation = scanner.nextInt();

        System.out.println("Type 1.complex 2.int");
        int type = scanner.nextInt();

        System.out.println("Nr threads: ");
        int nrTh = scanner.nextInt();

        if (type == 2){
            intSim(r1, c1, r2, c2, nrTh, operation);
        } else {
            complexSim(r1, c1, r2, c2, nrTh, operation);
        }
    }

    public static void main(String[] args) {
        while (true){
            try {
                System.out.println("New simulation");
                runSimulation();
                System.out.println();
            } catch (Exception e){
                System.out.println(e.getMessage());
            }
        }

    }
}
