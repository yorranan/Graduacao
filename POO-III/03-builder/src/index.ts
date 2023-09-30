import VehicleBuilder from "./builders/VehicleBuilder";
import Director from "./directors/Director";
import Vehicle from "./produts/Vehicle";

const builder: VehicleBuilder = new VehicleBuilder();
const director: Director = new Director(builder);

director.constructSedanCar();
const sedan: Vehicle = builder.getVehicle();
console.log("Criando veículo: " + sedan.vehicleType);
console.log("Motor: " + sedan.engine.power);
console.log("Transmissão: " + sedan.transmission);
console.log("Assentos: " + sedan.seats);
console.log("Número de rodas: " + sedan.wheels.length)
console.log("-------------------------------------------");
director.constructTruck();
const truck: Vehicle = builder.getVehicle();
console.log("Criando veículo: " + truck.vehicleType);
console.log("Motor: " + truck.engine.power);
console.log("Transmissão: " + truck.transmission);
console.log("Assentos: " + truck.seats);
console.log("Número de rodas: " + truck.wheels.length);
