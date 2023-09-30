import IHello from "./IHello";

export default class Hello implements IHello {

    sayHello() {
        console.log(" Hello World!");
    }
    
}