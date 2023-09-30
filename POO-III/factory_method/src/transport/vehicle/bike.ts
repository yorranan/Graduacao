import IVehicle from "./interface/IVehicle"

export default class Bike implements IVehicle{
    startRoute(): void {
        this.getCargo()
        console.log("Bicicleta: Iniciando o trajeto...")
    }
    getCargo(): void {
        console.log("Bicicleta: A encomenda foi retirada!")
    }

}