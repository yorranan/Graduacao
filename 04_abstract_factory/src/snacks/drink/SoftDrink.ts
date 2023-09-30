import IDrink from "./interfaces/IDrink";

export default class SoftDrink implements IDrink {
    startDelivery() {
        this.putDrink();
        console.log("Bebida enviada")
    }
    putDrink() {
        console.log("Preparando Soft Drink...")
    }

}