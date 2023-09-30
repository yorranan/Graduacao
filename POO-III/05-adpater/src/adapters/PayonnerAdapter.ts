import Payonner from "../payonner/Payonner";
import IPayPalPayment from "../paypal/IPayPalPayment";
import Token from "../utils/Token";

export default class PayonnerAdapter implements IPayPalPayment {
    private token: Token;

    constructor(private payonner: Payonner) {
        console.log("Adaptando payonner payment")
    }
    authToken(): Token {
        return new Token;
    }
    paypalPayment(): void {
        return this.payonner.sendPayment();
    }
    paypalReceive(): void {
        return this.payonner.receivePayment();
    }

}