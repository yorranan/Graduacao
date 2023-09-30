import IConsole from "./IConsole";

export default class XBox implements IConsole {
    constructor(){
        this.configureGame();
    }
    configureGame(): void {
        this.authToken();
        console.log("XB: Jogo configurado.");
    }
    authToken(): void {
        console.log("XB: Autenticando token...");
    }
}