import IPlataform from "./IPlataform";

export default class Youtube implements IPlataform{

    constructor() {
        this.configureRMTP();
        console.log("Plataforma do YouTube configurada")
    }
    configureRMTP(): void {
        this.authToken();
        console.log("Configurando broadcasting...");
    }
    authToken(): void {
        console.log("YouTube autenticando token...");
    }

}