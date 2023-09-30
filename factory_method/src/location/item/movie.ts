import IItem from "./interface/IItem";

export default class Movie implements IItem {
    start(): void {
        this.getDescription();
        console.log("Iniciando o filme...");
    }
    getDescription(): void {
        console.log("Mostrando descrição do filme");
    }
}