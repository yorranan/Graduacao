import IItem from "./interface/IItem";

export default class Game implements IItem {
    start(): void {
        this.getDescription();
        console.log("Iniciando Jogo");
    }
    getDescription(): void {
        console.log("Mostrando descrição do jogo");
    }
}
