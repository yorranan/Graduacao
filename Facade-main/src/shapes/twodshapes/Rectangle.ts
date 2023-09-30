import Shape from "../Shape";

export default class Rectangle extends Shape{

    draw(): void {
        console.log("O retângulo foi desenhado.");
    }

    area(): void {
        console.log("Área do retângulo é 42u.a.");
    }

}