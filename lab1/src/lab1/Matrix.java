package lab1;

/**
 * Created by Sebi on 06-Oct-17.
 */
public class Matrix {
    private Integer rows;
    private Integer cols;
    private double[][] data;

    public Matrix(Integer rows, Integer cols, double[][] data){
        this.rows = rows;
        this.cols = cols;
        this.data = data;
    }

    public Integer getRows() {
        return rows;
    }

    public void setRows(Integer rows) {
        this.rows = rows;
    }

    public Integer getCols() {
        return cols;
    }

    public void setCols(Integer cols) {
        this.cols = cols;
    }

    public double[][] getData() {
        return data;
    }

    public void setData(double[][] data) {
        this.data = data;
    }

    @Override
    public String toString(){
        String mat = rows + " " + cols + "\n";

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                mat = mat + data[i][j] + " ";
            }
            mat += "\n";
        }

        return mat;
    }
}
