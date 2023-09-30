import IConsole from "../console/IConsole";
import Play from "./Play";

export default class AdvancedPlay extends Play{
    constructor(private plataforma: IConsole){
        super(plataforma);
        this.challenge();
    }
    challenge() {
        this.playing();
        console.log("Advançando...")
    }
    playing(): void {
        this.result();
        console.log("Jogando altos jogos!");
    }
    result(): void {
        console.log("Resultado do jogo");
    }
}