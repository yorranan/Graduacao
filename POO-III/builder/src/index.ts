import SanduicheBuilder from "./builders/SanduicheBuilder";
import Director from "./directors/Director";
import Sanduiche from "./products/Sanduiche";

const builder: SanduicheBuilder = new SanduicheBuilder();
const director: Director = new Director(builder);

director.constructorHotDog();
const hotdog: Sanduiche = builder.getSanduiche();
console.log("Montando Saduíche: " + hotdog.sanduicheType);
console.log("Pão: " +  hotdog.bread);
console.log("Proteína: " + hotdog.protein);
console.log("Salada: " + hotdog.salad);
hotdog.sauce.forEach(item => {
    console.log("Molho: " + item)
})
director.constructorHotDog();
const misto: Sanduiche = builder.getSanduiche();
console.log("Montado o sanduíche: " + misto.sanduicheType);
console.log("Pão: " + misto.bread);
console.log("Recheio: " + misto.protein + " e " + misto.salad);

