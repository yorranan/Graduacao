import Bread from "../components/Bread";
import Protein from "../components/Protein";
import Salad from "../components/Salad";
import Sauce from "../components/Sauce";

export default interface IBuilder {
    reset();
    getSanduiche();
    setSanduicheType(value: SanduicheType);
    setBread(value: Bread);
    setProtein(value: Protein);
    setSalad(value: Salad);
    addSauces(value: Sauce);
}