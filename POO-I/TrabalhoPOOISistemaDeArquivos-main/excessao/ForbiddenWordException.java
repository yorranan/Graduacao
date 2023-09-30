package excessao;

public class ForbiddenWordException extends Exception {
    public ForbiddenWordException() {}

    public String toString() {
        return "O nome digitado está vazio";
    }
}