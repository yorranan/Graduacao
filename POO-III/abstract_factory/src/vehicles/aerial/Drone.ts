import IAircraft from "./interfaces/IAircraft";

export default class Drone implements IAircraft {
    startRoute(): void {
        this.checkWind();
        this.getCargo();
        console.log("Drone: Iniciando a subida...");
    }
    getCargo(): void {
        console.log("Drone: entrega obtida...");
    }
    checkWind(): void {
        console.log("Drone: ventos ok");
    }

}