import AiqFomeDelivery from "./factories/AiqFomeDelivery";
import IFoodDelivery from "./factories/IFoodDelivery";
import IDeliveryFactory from "./factories/interfaces/IDeliveryFactory";
import Company from "./snacks/consts/Company";
import Client from "./Clients/Client";

let currentCompany = Company.IFOOD;
let factory!: IDeliveryFactory;

switch(currentCompany) {
    case Company.AIQFOME:
        factory = new AiqFomeDelivery();
        break;
    case Company.IFOOD:
        factory = new IFoodDelivery();
        break;
    default: 
        console.log("Algo deu errado, tente novamente");
        break;
}

const client = new Client(factory)
client.startDelivery();