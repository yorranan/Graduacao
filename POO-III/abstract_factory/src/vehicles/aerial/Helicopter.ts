import IAircraft from "./interfaces/IAircraft";

export default class Helicopter implements IAircraft {
    startRoute(): void {
        this.checkWind();
        this.getCargo();
        console.log("Helicóptero: Iniciando a subida...");
    }
    getCargo(): void {
        console.log("Helicóptero: passageiros embarcados! Ligando Hélices...");
    }
    checkWind(): void {
        console.log("Helicóptero: Ventos a 22Km/h (ventos ok)");
    }

}