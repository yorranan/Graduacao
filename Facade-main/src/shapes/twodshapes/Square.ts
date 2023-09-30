import Shape from "../Shape";

export default class Square extends Shape{

    draw(): void {
        console.log("O quadrado foi desenhado.");
    }

    area(): void {
        console.log("Area do Quadrado é 1u.a.");
    }

}