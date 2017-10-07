package lab1.utils;

import lab1.Matrix;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;

/**
 * Created by Sebi on 06-Oct-17.
 */
public class MatrixFileWriter {
    /*
    Generates and writes a matrix to the given file
     */
    public void generateToFile(String path, int n, int m){
        try {
            PrintWriter printWriter = new PrintWriter(path, "UTF-8");
            MatrixGenerator matrixGenerator = new MatrixGenerator();
            System.out.println("Started matrix generation");

            printWriter.write(n + " " + m + "\n");
            Matrix mat = matrixGenerator.getMatrix(n, m);
            for (int i = 0; i < mat.getRows(); i++){
                for (int j = 0; j < mat.getCols(); j++){
                    printWriter.write(mat.getData()[i][j] + " ");
                }
                printWriter.write("\n");
            }


            printWriter.close();
            System.out.println("Matrix generation finished");

        } catch (FileNotFoundException | UnsupportedEncodingException e){
            System.out.println("Cant write to file");
        }
    }

    /*
    Saves a matrix to the given file
     */
    public void saveToFile(String path, Matrix matrix){
        try {
            PrintWriter printWriter = new PrintWriter(path, "UTF-8");
            //System.out.println("Started writing to file");

            printWriter.write(matrix.getRows() + " " + matrix.getCols() + "\n");
            for (int i = 0; i < matrix.getRows(); i++){
                for (int j = 0; j < matrix.getCols(); j++){
                   // System.out.println(i + " " + j);
                    printWriter.write(matrix.getData()[i][j] + " ");
                }
                printWriter.write("\n");
            }

            //System.out.println("Finished writing to file");
            printWriter.close();

        } catch (FileNotFoundException | UnsupportedEncodingException e){
            System.out.println("Cant write to file");
        }
    }
}
