import IDrink from "./interfaces/IDrink";

export default class Beer implements IDrink {
    startDelivery() {
        this.putDrink();
        console.log("Bebida enviada")
    }
    putDrink() {
        console.log("Preparando Cerveja...")
    }

}