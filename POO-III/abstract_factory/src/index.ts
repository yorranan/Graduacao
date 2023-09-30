import CLient from "./Clients/Client";
import LimeFactory from "./factories/LimeFactory";
import Lime from "./factories/LimeFactory";
import NineNineFactory from "./factories/NineNineFactory";
import UberFactory from "./factories/UberFactory";
import ITransportFactory from "./factories/interfaces/ITransportFactory";
import Company from "./vehicles/consts/Company";

let currentCompany = Company.LIME;
// O ponto de exclamação força a aceitar, isso é um erro do vscode.
let factory!: ITransportFactory;

declare var process;
if (process.argv.includes("--moto"))
{
}
else if (process.argv.includes("--aviao"))
{
    factory = new UberFactory(false)
}
else 
{
    console.log("Erro");
}
/*
switch(currentCompany){
    case Company.UBER:
        factory = new UberFactory();
        break;
    case Company.NINENINE:
        factory = new NineNineFactory();
        break;
    case Company.LIME:
        factory = new LimeFactory();
        break;
    default: 
        console.log("Compania não definida");
        break;
    */
}

const client = new CLient(factory);
client.startRoute();