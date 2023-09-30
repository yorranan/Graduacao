import Helicopter from "../vehicles/aerial/Helicopter";
import IAircraft from "../vehicles/aerial/interfaces/IAircraft";
import Motorcycle from "../vehicles/land/Motorcycle";
import ILand from "../vehicles/land/interfaces/ILand";
import ITransportFactory from "./interfaces/ITransportFactory";

export default class NineNineFactory implements ITransportFactory {
    createTransportVehicle(): ILand {
        console.log("Transporte via 99");
        return new Motorcycle();
    }
    createTransportAircraft(): IAircraft {
        console.log("Tranporte via 99")
        return new Helicopter();
    }

}