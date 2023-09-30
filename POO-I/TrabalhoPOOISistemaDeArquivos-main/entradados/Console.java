package entradados;
import java.io.*;

/*
 * Classe que é usada para ler a classe do console
 */
public class Console {
    
    public static String ler() {
        try {
            BufferedReader leitor = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("\nEsperando digitar... ");
            return leitor.readLine();
        }
        catch (IOException error) { 
            throw new RuntimeException("Erro ao ler o dado do teclado!");
        }
    }    
}
