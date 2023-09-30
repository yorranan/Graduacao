export default class Facebook implements Facebook {
    constructor() {
        this.configureRMTP();
        console.log("Plataforma do Facebook configurada")
    }
    configureRMTP(): void {
        this.authToken();
        console.log("Configurando broadcasting...");
    }
    authToken(): void {
        console.log("Facebook autenticando token...");
    }
}