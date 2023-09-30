import * as readline from "readline";
import Server from "./server/Server";
import CheckUserMiddleware from "./middlewares/CheckUserMiddleware";
import CheckPermissionMiddleware from "./middlewares/CheckPermissionMiddleware";
import CheckWeakPasswordMiddleware from "./middlewares/CheckWeakPasswordMiddleware";

declare var process;
const server = new Server();

function setPromptQuestions() {
    const rl = readline.createInterface ({
        input: process.stdin,
        output: process.stdout
    });

    rl.question("Digite seu email: ", email => {
        rl.question("Digite sua senha: ", password => {
            server.logIn(email, password);
            rl.close();
        })
    })

    rl.on("close", () => setPromptQuestions());
}
// essas chamadas tem quer ser feita na chamada de ordem em que vai ser trabalhada:
const middleware = new CheckUserMiddleware();
middleware.linkWith(new CheckPermissionMiddleware());
middleware.linkWith(new CheckWeakPasswordMiddleware());
server.setMiddleware(middleware);
setPromptQuestions();