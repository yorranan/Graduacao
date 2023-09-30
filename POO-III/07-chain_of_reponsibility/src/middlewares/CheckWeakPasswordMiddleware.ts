import internal from "stream";
import Database from "../server/Database";
import Middleware from "./Middleware";

export default class CheckWeakPasswordMiddleware extends Middleware{
    public check(email: string, password: string) {
        const TAMANHO_MINIMO =  6;
        if (password.length <= TAMANHO_MINIMO)
        {
            console.log("Senha fraca!");
            return false;
        }
        console.log("Senha segura");
        return this.checkNext(email, password);
    }

}