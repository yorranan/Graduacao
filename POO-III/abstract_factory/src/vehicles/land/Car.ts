import ILand from "./interfaces/ILand";

export default class  Car implements ILand{
    startRoute(): void {
        this.getCargo();
        console.log("Carro: Iniciando o trajeto...")
    }
    getCargo(): void {
        console.log("Carro: passageiro embarcado")
    }
}