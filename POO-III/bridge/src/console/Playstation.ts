import IConsole from "./IConsole";

export default class Playstation implements IConsole {
    constructor(){
        this.configureGame();
    }
    configureGame(): void {
        this.authToken();
        console.log("PS: Jogo configurado.");
    }
    authToken(): void {
        console.log("PS: Autenticando token...");
    }

}