import Transport from "./Transport"
import Car from "./vehicle/car"
import IVehicle from "./vehicle/interface/IVehicle"


export default class CarTransport extends Transport{
    protected createTransport(): IVehicle {
        return new Car();
    }
}