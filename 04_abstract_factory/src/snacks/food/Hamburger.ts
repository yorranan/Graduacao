import IFood from "./interfaces/IFood";

export default class Hamburger implements IFood{
    startDelivery() {
        this.prepareFood();
        console.log("Comida enviada")
    }
    prepareFood() {
        console.log("Preparando hamburger...")
    }

}