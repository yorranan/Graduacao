import IConsole from "../console/IConsole";
import IPlay from "./IPlay";

export default class Play implements IPlay{
    constructor(private console: IConsole){
        this.playing();
    }
    playing(): void {
        this.result();
        console.log("Jogando altos jogos!");
    }
    result(): void {
        console.log("Resultado do jogo");
    }
}