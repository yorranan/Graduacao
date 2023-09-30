import Hello from "../shapes/hello/Hello";

export default class HelloMaker {
    private say: Hello;

    constructor(){
        this.say = new Hello();
    }

    sayHello(){
        this.say.sayHello();
    }
}