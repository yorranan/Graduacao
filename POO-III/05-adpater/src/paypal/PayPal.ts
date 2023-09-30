import Token from "../utils/Token";
import IPayPalPayment from "./IPayPalPayment";

export default class PayPal implements IPayPalPayment {
  private token: Token;

  authToken(): Token {
    return new Token();
  }
  paypalPayment(): void {
    this.token = this.authToken();
    console.log("Token: " + this.token.token);
    console.log("Enviando pagamento via PayPal.");
  }
  paypalReceive(): void {
    this.token = this.authToken();
    console.log("Token: " + this.token.token);
    console.log("Recebendo pagamento via PayPal.");
  }
}
