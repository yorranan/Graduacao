import ICorreios from "./ICorreios";

export default class Correios implements ICorreios{
    sendCorreios() {
        console.log("Enviando via correios...");
    }
    receiveCorreios() {
        console.log("Enviando via correios...");
    }

}