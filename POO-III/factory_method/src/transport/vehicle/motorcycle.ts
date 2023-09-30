import IVehicle from "./interface/IVehicle"

export default class Motorcycle implements IVehicle{
    startRoute(): void {
        this.getCargo()
        console.log("Moto: iniciando a entrega...")
    }
    getCargo(): void {
        console.log("Moto: encomenda retirada!")
    }
}