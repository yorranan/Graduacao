import Shape from "../Shape";

export default class Triangle extends Shape{

    draw(): void {
        console.log("O triângulo foi desenhado.");
    }

    area(): void {
        console.log("Area do triangulo é 300u.a.");
    }

}