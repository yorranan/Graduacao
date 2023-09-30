import IPlataform from "../plataform/IPlataform";
import Live from "./Live";

export default class AdvancedLive extends Live{
    constructor(plataform: IPlataform){
        // a palavra reservada super permite instanciar objetos da superclasse, fazendo o que está nessa subir para onde ela está puxando.
        super(plataform);
    }
    subtitles(): void {
        console.log("LEGENDA MUITO BRABA");
    }
    comments(): void {
        console.log("COMENTÁRIOS SUPER IMPORTANTES");
    }
}
