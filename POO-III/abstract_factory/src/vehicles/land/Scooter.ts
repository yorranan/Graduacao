import ILand from "./interfaces/ILand";

export default class  Scooter implements ILand{
    startRoute(): void {
        this.getCargo();
        console.log("Patinete: Iniciando a viagem...")
    }
    getCargo(): void {
        console.log("Patinente: cliente pegou o patinete")
    }
}