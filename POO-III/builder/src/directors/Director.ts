import IBuilder from "../builders/IBuilder";
import Bread from "../components/Bread";
import Protein from "../components/Protein";
import Salad from "../components/Salad";
import Sauce from "../components/Sauce";

export default class Director {
    constructor(private builder: IBuilder) {};

    constructorHotDog(){
        this.builder.setBread(Bread.PAODEHOTDOG);
        this.builder.setProtein(Protein.VINA);
        this.builder.setSalad(Salad.PURE);
        this.builder.addSauces(Sauce.KETCHUP);
        this.builder.addSauces(Sauce.MAIONESE);
    }
    constructorMistoQuente(){
        this.builder.setBread(Bread.PAOCARECA);
        this.builder.setSalad(Salad.QUEIJO);
        this.builder.setProtein(Protein.PRESUNTO);
    }
}