// a classe abstrata não precisa ser instanciada
export default abstract class Middleware {
    public next: Middleware;

    public linkWith(next: Middleware): Middleware {
        this.next = next;
        return next;
    }

    protected checkNext(email: string, password: string): boolean {
        if (this.next === undefined) {
            return true;
        }
        return this.next.check(email, password);
    }
    // esse método vai ser implementado em cada uma classe que ele vai ser extendido
    // o método abstrato que necessita ser implementado na classe
    public abstract check(email: string, password: string);
}