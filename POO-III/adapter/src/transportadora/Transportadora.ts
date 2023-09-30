import ITransportadora from "./ITransportadora";

export default class Transportadora implements ITransportadora {
    send() {
        console.log("Enviando através da transportadora...");
    }
    receive() {
        console.log("Recebendo através da transportadora...");
    }
    
}