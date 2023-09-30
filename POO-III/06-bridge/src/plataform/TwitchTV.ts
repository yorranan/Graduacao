import IPlataform from "./IPlataform";

export default class TwitchTV implements IPlataform {
    constructor() {
        this.configureRMTP();
        console.log("Plataforma da Twitch configurada")
    }
    configureRMTP(): void {
        this.authToken();
        console.log("Configurando broadcasting...");
    }
    authToken(): void {
        console.log("Twitch autenticando token...");
    }
}