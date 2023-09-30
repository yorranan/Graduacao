import SoftDrink from "../snacks/drink/SoftDrink";
import IDrink from "../snacks/drink/interfaces/IDrink";
import HotDog from "../snacks/food/HotDog";
import IFood from "../snacks/food/interfaces/IFood";
import IDeliveryFactory from "./interfaces/IDeliveryFactory";

export default class IFoodDelivery implements IDeliveryFactory{
    CreateDeliveryDrink(): IDrink {
        console.log("Pedido Feito Através do IFood")
        return new SoftDrink();
    }
    CreateDeliveryFood(): IFood {
        return new HotDog();
    }

}