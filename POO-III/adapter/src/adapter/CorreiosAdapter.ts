import Correios from "../correios/Correios";
import ITransportadora from "../transportadora/ITransportadora";

export default class CorreiosAdapter implements ITransportadora {
    constructor(private correios: Correios) {
        console.log("Adaptando Correios");
    }
    send() {
        return this.correios.sendCorreios();
    }
    receive() {
        return this.correios.receiveCorreios();
    }

    
}