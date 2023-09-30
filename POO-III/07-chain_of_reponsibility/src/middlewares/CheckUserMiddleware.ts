
import Database from "../server/Database";
import Middleware from "./Middleware";

export default class CheckUserMiddleware extends Middleware {
    public check(email: string, password: string) {
        if (email.indexOf("@") === -1) {
            console.log("Email inválido!");
            return false;
        }

        const verificarEmail = (Database.filter(item => item.email === email));

        if (!verificarEmail.length) {
            console.log("Email não cadastrado!");
            return false;
        }

        const verificarPassword = (Database.filter(item => item.password === password));

        if (!verificarPassword.length) {
            console.log("Senha incorreta!");
            return false;
        }

        return this.checkNext(email, password);
    }
}