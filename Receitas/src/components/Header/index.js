import { Link } from "react-router-dom";
import "./style.css";

function Header() {
  return (
    <header>
      <div>
        <Link className="h1" to="/">Inicio</Link>
      </div>
      <br />
        <p>
          <Link to="/criar">Criar</Link>
        </p>
    </header>
  );
}

export default Header;
