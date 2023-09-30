import CorreiosAdapter from "./adapter/CorreiosAdapter";
import Correios from "./correios/Correios";
import ITransportadora from "./transportadora/ITransportadora";
import Transportadora from "./transportadora/Transportadora";

console.log("-------------------------------------------------------");
const package1: ITransportadora = new Transportadora();
package1.send();
package1.receive();
console.log("-------------------------------------------------------");
const package2: ITransportadora = new CorreiosAdapter(new Correios());
package2.send();
package2.receive();
console.log("-------------------------------------------------------")
