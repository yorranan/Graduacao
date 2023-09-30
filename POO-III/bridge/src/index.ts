import IConsole from "./console/IConsole";
import Playstation from "./console/Playstation";
import XBox from "./console/XBox";
import AdvancedPlay from "./play/AdvancedPlay";
import Play from "./play/Play";

function jogarAvancado(plataforma: IConsole) {
    const jogo = new AdvancedPlay(plataforma);
    jogo.challenge();
    jogo.playing();
    jogo.result();
}

function jogar(plataforma: IConsole) {
    const jogo = new Play(plataforma);
    jogo.playing();
    jogo.result();
}

console.log("..........................................");
jogar(new XBox());
console.log("..........................................");
jogar(new Playstation());
console.log("..........................................");
jogarAvancado(new XBox());
console.log("..........................................");
jogarAvancado(new Playstation());
console.log("..........................................");