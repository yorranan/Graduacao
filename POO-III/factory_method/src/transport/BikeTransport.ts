import Transport from "./Transport"
import Bike from "./vehicle/bike"
import IVehicle from "./vehicle/interface/IVehicle"

export default class BikeTransport extends Transport{
    protected createTransport(): IVehicle {
        return new Bike()
    }

}