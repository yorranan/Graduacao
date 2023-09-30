import IAircraft from "./interfaces/IAircraft";

export default class Airplane implements IAircraft {
    startRoute(): void {
        this.checkWind();
        this.getCargo();
        console.log("Avião: Iniciando a decolagem...");
    }
    getCargo(): void {
        console.log("Avião: passageiros embarcados!");
    }
    checkWind(): void {
        console.log("Avião: Ventos a 25Km/h (ventos ok)");
    }

}