import PayonnerAdapter from "./adapters/PayonnerAdapter";
import IPayonnerPayment from "./payonner/IPayonnerPayment";
import Payonner from "./payonner/Payonner";
import IPayPalPayment from "./paypal/IPayPalPayment";
import PayPal from "./paypal/PayPal";

const payment: IPayPalPayment = new PayPal();
payment.paypalPayment();
payment.paypalReceive();
console.log("----------------------------------------------");
const payment2: IPayonnerPayment = new Payonner();
payment2.sendPayment();
payment2.receivePayment();
console.log("----------------------------------------------");
const payment1: IPayPalPayment = new PayonnerAdapter(new Payonner());
payment1.paypalPayment();
payment1.paypalReceive();