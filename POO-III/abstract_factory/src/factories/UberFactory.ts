import Airplane from "../vehicles/aerial/Airplane";
import IAircraft from "../vehicles/aerial/interfaces/IAircraft";
import Car from "../vehicles/land/Car";
import ILand from "../vehicles/land/interfaces/ILand";
import ITransportFactory from "./interfaces/ITransportFactory";

export default class UberFactory implements ITransportFactory{
    createTransportVehicle(): ILand {
        console.log("Transporte via Uber");
        return new Car();
    }
    createTransportAircraft(): IAircraft {
        console.log("Transporte via Uber")
        return new Airplane();
    }

}