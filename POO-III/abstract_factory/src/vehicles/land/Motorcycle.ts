import ILand from "./interfaces/ILand";

export default class  Motorcycle implements ILand{
    startRoute(): void {
        this.getCargo();
        console.log("Moto: Iniciando a entrega...")
    }
    getCargo(): void {
        console.log("Moto: objeto recebido")
    }
}