import Facebook from "./plataform/Facebook";
import IPlataform from "./plataform/IPlataform";
import TwitchTV from "./plataform/TwitchTV";
import Youtube from "./plataform/YouTube";
import AdvancedLive from "./transmission/AdvancedLive";
import Live from "./transmission/Live";

function startAdvancedLive(plataform: IPlataform) {
    console.log("Aguarde...");
    const live = new AdvancedLive(plataform);
    live.broadcasting();
    live.result();
    live.subtitles();
    live.comments();
}

function startLive(plataform: IPlataform) {
    console.log("Aguarde...");
    const live = new Live(plataform);
    live.broadcasting();
    live.result();
}
console.log("..........................................");
startLive(new Youtube());
console.log("..........................................");
startLive(new TwitchTV());
console.log("..........................................");
startLive(new Facebook());
console.log("..........................................");
startAdvancedLive(new Youtube());
console.log("..........................................");
startAdvancedLive(new TwitchTV());
console.log("..........................................");
startAdvancedLive(new Facebook());
console.log("..........................................");