import Bread from "../components/Bread";
import Protein from "../components/Protein";
import Salad from "../components/Salad";
import Sauce from "../components/Sauce";
import Sanduiche from "../products/Sanduiche";
import IBuilder from "./IBuilder";

export default class SanduicheBuilder implements IBuilder {

    private sanduiche = new Sanduiche();

    reset() {
        this.sanduiche = new Sanduiche();
    }
    getSanduiche() {
        const result = this.sanduiche;
        this.reset;
        return result;
    }
    setSanduicheType(value: SanduicheType){
        this.sanduiche.sanduicheType = value;
    }
    setBread(value: Bread) {
        this.sanduiche.bread = value;
    }
    setProtein(value: Protein) {
        this.sanduiche.protein = value;
    }
    setSalad(value: Salad) {
        this.sanduiche.salad = value;
    }
    addSauces(value: Sauce) {
        this.sanduiche.addSauce(value);
    }
}