import java.io.*;
import java.lang.*;
import java.util.*;

public class imparesEvaluador {
    private static String nextLine = "";
    private static int nextIndex = 0;
    private static BufferedReader reader;
    
    private static String readToken() throws IOException {
        while (true) {
            while (nextIndex < nextLine.length() && nextLine.charAt(nextIndex) == ' ') nextIndex++;
            if (nextIndex == nextLine.length()) {
                nextLine = reader.readLine();
                nextIndex = 0;
            } else {
                break;
            }
        }
        int baseIndex = nextIndex++;
        while (nextIndex < nextLine.length() && nextLine.charAt(nextIndex) != ' ') nextIndex++;
        return nextLine.substring(baseIndex, nextIndex);
    }
    
    public static void main(String [] args) throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)))) {
            int N;
            N = Integer.parseInt(readToken());
            ArrayList<ArrayList<Integer>> subordinados;
            subordinados = new ArrayList<>(N);
            for (int i0 = 0; i0 < N; i0++) {
                ArrayList<Integer> aux0;
                int auxSize1;
                auxSize1 = Integer.parseInt(readToken());
                aux0 = new ArrayList<>(auxSize1);
                for (int i1 = 0; i1 < auxSize1; i1++) {
                    int aux1;
                    aux1 = Integer.parseInt(readToken());
                    aux0.add(aux1);
                }
                subordinados.add(aux0);
            }
            int returnedValue;
            returnedValue = impares.impares(subordinados);
            writer.println(returnedValue);
        }
    }
}
