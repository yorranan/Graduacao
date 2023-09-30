import Beer from "../snacks/drink/Beer";
import IDrink from "../snacks/drink/interfaces/IDrink";
import Hamburger from "../snacks/food/Hamburger";
import IFood from "../snacks/food/interfaces/IFood";
import IDeliveryFactory from "./interfaces/IDeliveryFactory";

export default class AiqFomeDelivery implements IDeliveryFactory{
    CreateDeliveryDrink(): IDrink {
        console.log("Pedido feiro através do AiqFome")
        return new Beer();
    }
    CreateDeliveryFood(): IFood {
        return new Hamburger();
    }

}