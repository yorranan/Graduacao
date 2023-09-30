import Drone from "../vehicles/aerial/Drone";
import IAircraft from "../vehicles/aerial/interfaces/IAircraft";
import Scooter from "../vehicles/land/Scooter";
import ILand from "../vehicles/land/interfaces/ILand";
import ITransportFactory from "./interfaces/ITransportFactory";

export default class LimeFactory implements ITransportFactory{
    createTransportVehicle(): ILand {
        console.log("Transporte via Lime");
        return new Scooter();
    }
    createTransportAircraft(): IAircraft {
        console.log("Transporte via Lime");
        return new Drone();
    }

}