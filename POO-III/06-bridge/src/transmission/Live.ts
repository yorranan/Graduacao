import IPlataform from "../plataform/IPlataform";
import ITransmission from "./ITransmission";

export default class Live implements ITransmission {

    constructor (private plataform: IPlataform) {
        console.log("Transmissão iniciada.")
    }
    broadcasting(): void {
        console.log("Inciando a transmissão");
    }
    result(): void {
        console.log("*** Noir *** :)");
    }

}