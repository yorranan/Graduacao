package arquivo;
import java.io.*;

public class GerenciadorClientesArquivo implements GerenciadorClientes{

	public void gravarClientes(String nome) {
		BufferedWriter writer = null;
		try {
			writer = new BufferedWriter(new FileWriter("clientes.txt", true));
			writer.write(nome);
			writer.newLine();
		} catch (IOException exc) {
			System.out.println("Erro de I/O" + exc);
		} finally {
			try {
				if (writer != null)
					writer.close();
			} catch (IOException exc) {
				System.out.println("Fechando arquivo clientes.txt" + exc);
			}
		}
	}

    public void lerClientes() {
        String s;

        // Cria e usa um FileReader encapsulado em um BufferedReader.
        try (BufferedReader br = new BufferedReader(new FileReader("clientes.txt"))) {
            while ((s = br.readLine()) != null) {
                System.out.println(s);
            }
        } catch (IOException exc) {
            System.out.println("Erro de I/O: " + exc);
        }
    }
}
