import Endereco from "./Endereco"
import Produto from "./Produto"
import Telefone from "./Telefone"
import Cliente from "./Cliente"
import Venda from "./Venda"

let endereco: Endereco = new Endereco("Rua Girassol", 610, "Guarapuava", "PR")
let telefone1: Telefone = new Telefone("41", 998035718, 0)
let telefone2: Telefone = new Telefone("42", 991123456, 0)
let produto1: Produto = new Produto(0, "Sabonete", 2.53)
let produto2: Produto = new Produto(1, "Batata-Frita", 4.50)
let produto3: Produto = new Produto(2, "Molho de Tomate", 6.10)
let produto4: Produto = new Produto(3, "Desodorante", 10.99)
let cliente1: Cliente = new Cliente("Aline", "12345678900", 22042004, 1, endereco, [telefone1, telefone2])
let venda1: Venda = new Venda(0, 662023, cliente1, [produto1, produto2, produto1, produto3, produto4])

console.log("--- RESULTADO DA BUSCA ---")
console.log("Cliente: " + cliente1.nome)
console.log("Produtos comprados:")

let i: number = 0
venda1.produtos.forEach((produto) => {
    i++
    console.log(i + " - " + produto.descricao + " " + produto.valor)
})

i = 0
cliente1.telefones.forEach((telefone) => {
    i++
    console.log("Telefone " + i + ": " + "(" + telefone.ddd + ") " + telefone.numero)
})
let total: number = venda1.calcularTotal(venda1.produtos)
console.log("Total da compra = " + total )
