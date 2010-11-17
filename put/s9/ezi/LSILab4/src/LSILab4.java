import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.util.Vector;

import Jama.Matrix;
import Jama.SingularValueDecomposition;

public class LSILab4 {
    Matrix M;

    Matrix Q;

    public static void main(String[] args) {
        LSILab4 lsi = new LSILab4();
        lsi.go();
    }

    private void go() {
        // init the matrix and the query
        M = readMatrix("data.txt");
        Q = readMatrix("query.txt");

        // print
        System.out.println("Matrix:");
        M.print(3, 2);

        // print the dimensions of the matrix
        System.out.println("M: " + dim(M));
        // print the query
        System.out.println("Query:");
        Q.print(3, 2);
        System.out.println("Q: " + dim(Q));

        // do svd
        svd();
    }

    private void svd() {

        // TODO implement your solution

        SingularValueDecomposition svd = new SingularValueDecomposition(M);
        // get K, S, and D
        Matrix K = svd.getU();
        Matrix S = svd.getS();
        Matrix D = svd.getV().transpose();

        // set number of largest singular values to be considered
        int s = 3;

        // cut off appropriate columns and rows from K, S, and D
        K = K.getMatrix(0, K.getRowDimension() - 1, 0, s - 1);
        S = S.getMatrix(0, s - 1, 0, s - 1);
        D = D.getMatrix(0, s - 1, 0, D.getColumnDimension() - 1);
        D = D.transpose();

        // transform the query vector
        Matrix q_t = Q.transpose();

        // compute similaraty of the query and each of the documents, using
        // cosine measure
        Matrix sim_q = q_t.times(K).times(S.inverse());

        double[][] D_array = D.getArray();
        double[][] sim_q_array = sim_q.getArray();
        double[] Sim = new double[D.getRowDimension()];
        double sim_q_sqrt = 0;

        for (int column = 0; column < sim_q.getColumnDimension(); column++) {
            sim_q_sqrt += sim_q_array[0][column] * sim_q_array[0][column];
        }
        sim_q_sqrt = Math.sqrt(sim_q_sqrt);

        for (int row = 0; row < D.getRowDimension(); row++) {
            double tmp_mul = 0;
            double k_mul = 0;
            for (int column = 0; column < D.getColumnDimension(); column++) {
                tmp_mul += D_array[row][column] * sim_q_array[0][column];
                k_mul += D_array[row][column] * D_array[row][column];
            }
            Sim[row] = tmp_mul/(sim_q_sqrt*Math.sqrt(k_mul));
        }
        
        // Print the result
        System.out.println("\n Similarity!");
        DecimalFormat df = new DecimalFormat("#.##");
        for (int i = 0; i < Sim.length; i++) {
            System.out.println("D_"+(i+1) +" = " +df.format(Sim[i]));
        }
    }

    // returns the dimensions of a matrix
    private String dim(Matrix M) {
        return M.getRowDimension() + "x" + M.getColumnDimension();
    }

    // reads a matrix from a file
    private Matrix readMatrix(String filename) {
        Vector<Vector<Double>> m = new Vector<Vector<Double>>();
        int colums = 0;
        try {
            BufferedReader br = new BufferedReader(new FileReader(filename));
            while (br.ready()) {
                Vector<Double> row = new Vector<Double>();
                m.add(row);
                String line = br.readLine().trim();
                StringTokenizer st = new StringTokenizer(line, ", ");
                colums = 0;
                while (st.hasMoreTokens()) {
                    row.add(Double.parseDouble(st.nextToken()));
                    colums++;
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        int rows = m.size();
        Matrix M = new Matrix(rows, colums);
        int rowI = 0;
        for (Vector<Double> vector : m) {
            int colI = 0;
            for (Double d : vector) {
                M.set(rowI, colI, d);
                colI++;
            }
            rowI++;
        }
        return M;
    }
}
