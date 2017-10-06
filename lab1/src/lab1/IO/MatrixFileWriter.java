package lab1.IO;

import lab1.Matrix;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;

/**
 * Created by Sebi on 06-Oct-17.
 */
public class MatrixFileWriter {
    public void generateToFile(String path, int n, int m){
        try {
            PrintWriter printWriter = new PrintWriter(path, "UTF-8");
            MatrixGenerator matrixGenerator = new MatrixGenerator();
            printWriter.write(matrixGenerator.getMatrix(n, m).toString());
            printWriter.close();

        } catch (FileNotFoundException | UnsupportedEncodingException e){
            System.out.println("Cant write to file");
        }
    }

    public void saveToFile(String path, Matrix matrix){
        try {
            PrintWriter printWriter = new PrintWriter(path, "UTF-8");

            printWriter.write(matrix.toString());

            printWriter.close();

        } catch (FileNotFoundException | UnsupportedEncodingException e){
            System.out.println("Cant write to file");
        }
    }
}
