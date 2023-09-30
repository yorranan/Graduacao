import Shape from "../Shape";

export default class Circle extends Shape{

    draw(): void {
        console.log("O círculo foi desenhado.");
    }

    area(): void {
        console.log("Área do Círculo é 42.a.");
    }

}